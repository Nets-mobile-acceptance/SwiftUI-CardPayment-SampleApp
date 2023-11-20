//
//  PiaSDKView.swift
//  CustometCase
//

import SwiftUI
import Pia

struct PiaSDKView: UIViewControllerRepresentable {
    typealias UIViewControllerType = UIViewController
    
    func makeUIViewController(context: Context) -> UIViewController {
        let merchantDetails = MerchantDetails.merchant(withID: StaticData.merchantId, inTest: false)
        
        let cardProcessCall = PaymentProcess.cardPayment(
            withMerchant: merchantDetails,
            amount: StaticData.orderValue,
            currency: StaticData.orderCurrency) { _, callback in
            let cardRegistrationResponse = CardRegistrationResponse.success(
                withTransactionID: StaticData.transactionId,
                redirectURL: StaticData.redirectUrl)
                
            callback(cardRegistrationResponse)
        }
    
        let viewController = PiaSDK.controller(for: cardProcessCall) { vc, transactionID in
            print(transactionID ?? "")
        } cancellation: { vc, transactionID in
            print(transactionID ?? "")
        } failure: { vc, error in
            print(error)
        }
        
        return viewController
    }

    func updateUIViewController(_ uiViewController: UIViewController, context: Context) {
        // Update the view controller if needed
    }
}

extension PiaSDKView {
    enum StaticData {
        static let merchantId: String = "<Put your Merchant ID>"
        static let transactionId: String = "<Put test transaction ID>"
        static let redirectUrl: String = "<Put test redirect URL>"
        static let orderValue: UInt = 100 // 1.00
        static let orderCurrency: String = "EUR"
    }
}

#Preview {
    PiaSDKView()
}
