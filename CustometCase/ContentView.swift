//
//  ContentView.swift
//  CustometCase
//


import SwiftUI
import Pia

struct ContentView: View {
    var body: some View {
        NavigationView {
            VStack(spacing: 24) {
                Text("Customer Case debug app")
                NavigationLink("Pay with Pia SDK", destination: PiaSDKView())
            }
        }
    }
}

#Preview {
    ContentView()
}
