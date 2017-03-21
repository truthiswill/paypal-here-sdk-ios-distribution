/**
 * PPRetailInvoice.h
 *
 * DO NOT EDIT THIS FILE! IT IS AUTOMATICALLY GENERATED AND SHOULD NOT BE CHECKED IN.
 * Generated from: node_modules/paypal-invoicing/lib/Invoice.js
 *
 * 
 */

#import "PayPalRetailSDKTypeDefs.h"
#import "PPRetailObject.h"

@class PPRetailSDK;
@class PPRetailError;
@class PPRetailPayPalErrorInfo;
@class PPRetailAccountSummary;
@class PPRetailAccountSummarySection;
@class PPRetailInvoiceAddress;
@class PPRetailInvoiceAttachment;
@class PPRetailInvoiceBillingInfo;
@class PPRetailInvoiceCCInfo;
@class PPRetailCountries;
@class PPRetailCountry;
@class PPRetailInvoiceCustomAmount;
@class PPRetailInvoice;
@class PPRetailInvoiceActions;
@class PPRetailInvoiceListRequest;
@class PPRetailInvoiceListResponse;
@class PPRetailInvoiceMetaData;
@class PPRetailInvoiceTemplatesResponse;
@class PPRetailInvoicingService;
@class PPRetailInvoiceItem;
@class PPRetailInvoiceMerchantInfo;
@class PPRetailInvoiceNotification;
@class PPRetailInvoicePayment;
@class PPRetailInvoicePaymentTerm;
@class PPRetailInvoiceRefund;
@class PPRetailInvoiceSearchRequest;
@class PPRetailInvoiceShippingInfo;
@class PPRetailInvoiceTemplate;
@class PPRetailInvoiceTemplateSettings;
@class PPRetailMerchant;
@class PPRetailTransactionContext;
@class PPRetailSignatureReceiver;
@class PPRetailReceiptOptionsViewContent;
@class PPRetailReceiptEmailEntryViewContent;
@class PPRetailReceiptSMSEntryViewContent;
@class PPRetailReceiptViewContent;
@class PPRetailCard;
@class PPRetailBatteryInfo;
@class PPRetailMagneticCard;
@class PPRetailPaymentDevice;
@class PPRetailEmvDevice;
@class PPRetailSecureEntryOptions;
@class PPRetailNumericEntryOptions;
@class PPRetailManuallyEnteredCard;
@class PPRetailDeviceUpdate;
@class PPRetailDeviceOperationResultHandler;
@class PPRetailVirtualPaymentDevice;
@class PPRetailPayer;
@class PPRetailTransactionRecord;

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/**
 * Invoice is the fundamental transaction record for retail payments.
 * It contains header data, such as buyer and seller information and
 * {@link InvoiceItem line items} with unit prices, quantities, etc.
 */
@interface PPRetailInvoice : PPRetailObject

    /**
    * The currency for all amounts on this invoice @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSString* currency;
    /**
    * The date the invoice was 'enabled'. Can be set by user.
    */
    @property (nonatomic,strong,nullable) NSDate* invoiceDate;
    /**
    * The id assigned by PayPal for this invoice
 * (if it has been saved to PayPal at some point) @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSString* payPalId;
    /**
    * The unique order number that can be assigned by you
 * (you must ensure uniqueness) or automatically generated by PayPal
    */
    @property (nonatomic,strong,nullable) NSString* number;
    /**
    * The current status of the invoice @readonly
    */
    @property (nonatomic,assign,readonly) PPRetailInvoiceStatus status;
    /**
    * Reference data such as PO Number to be added to invoice.
 * 60 characters max.
    */
    @property (nonatomic,strong,nullable) NSString* reference;
    /**
    * Merchant email address and contact
 * information (email defaults to a PayPal no-reply address)
    */
    @property (nonatomic,strong,nullable) PPRetailInvoiceMerchantInfo* merchantInfo;
    /**
    * Information about the payer or
 * intended payer of the invoice
    */
    @property (nonatomic,strong,nullable) PPRetailInvoiceBillingInfo* billingInfo;
    /**
    * The shipping address for this
 * invoice (usually blank in retail use cases)
    */
    @property (nonatomic,strong,nullable) PPRetailInvoiceShippingInfo* shippingInfo;
    /**
    * Prices for items on this invoice are INCLUSIVE
 * of tax - defaults to false.
    */
    @property (nonatomic,assign) BOOL taxInclusive;
    /**
    * Taxes for line items are calculated
 * after any discounts - defaults to false
    */
    @property (nonatomic,assign) BOOL taxCalculatedAfterDiscount;
    /**
    * The list of items on this invoice
    */
    @property (nonatomic,strong,nullable) NSArray* items;
    /**
    * Get the number of items on this invoice @readonly
    */
    @property (nonatomic,assign,readonly) int itemCount;
    /**
    * Describes when payment is expected on the
 * invoice (defaults to DueOnReceipt)
    */
    @property (nonatomic,strong,nullable) PPRetailInvoicePaymentTerm* paymentTerms;
    /**
    * The amount of gratuity to be applied to the invoice, if any
    */
    @property (nonatomic,strong,nullable) NSDecimalNumber* gratuityAmount;
    /**
    * Discount amount applied to the invoice
    */
    @property (nonatomic,strong,nullable) NSDecimalNumber* discountAmount;
    /**
    * Base object for all financial value related fields
 * (balance, payment due, etc.)
    */
    @property (nonatomic,strong,nullable) NSDecimalNumber* minimumAmountDue;
    /**
    * Discount percentage applied to the invoice
    */
    @property (nonatomic,strong,nullable) NSDecimalNumber* discountPercentage;
    /**
    * A note to the customer
    */
    @property (nonatomic,strong,nullable) NSString* note;
    /**
    * The shipping cost to be applied to the invoice, if any
    */
    @property (nonatomic,strong,nullable) NSDecimalNumber* shippingAmount;
    /**
    * The shipping tax rate, as percent of the
 * total shipping amount.
    */
    @property (nonatomic,strong,nullable) NSDecimalNumber* shippingTaxRate;
    /**
    * The name of the shipping tax.
    */
    @property (nonatomic,strong,nullable) NSString* shippingTaxName;
    /**
    * General terms of the invoice. 4000 characters max.
    */
    @property (nonatomic,strong,nullable) NSString* termsAndConditions;
    /**
    * Bookkeeping memo that is private to the merchant.
 * 150 characters max.
    */
    @property (nonatomic,strong,nullable) NSString* merchantMemo;
    /**
    * Has this invoice changed since the last time it was
 * saved to the server? @readonly
    */
    @property (nonatomic,assign,readonly) BOOL isDirtyFromServer;
    /**
    * If false, this invoice doesn't know what items are in its item list.
 * This can happen when only "summary" information has been fetched from the server
 * (typically as the result of a search). You can get the total, but items and subtotals
 * totals aren't available until you call getDetails. @readonly
    */
    @property (nonatomic,assign,readonly) BOOL hasDetails;
    /**
    * The total amount due on the invoice @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSDecimalNumber* total;
    /**
    * The subtotal of the items on the invoice @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSDecimalNumber* subTotal;
    /**
    * The total tax on the items (as opposed to the shipping tax,
 * for example) @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSDecimalNumber* itemTax;
    /**
    * The total amount of discounts applied to the invoice items
 * and overall invoice @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSDecimalNumber* totalDiscount;
    /**
    * An associative array of tax rate names to the total tax on the
 * invoice from that rate @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSDictionary* taxBreakdown;
    /**
    * Indicates if a partial payment is allowed over the invoice.
 * defaults to false
    */
    @property (nonatomic,assign) BOOL allowPartialPayment;
    /**
    * an array of CCInfo Email addresses which should be marked as
 * Carbon Copy (CC) while the invoice is sent via email. Only email address under participant is
 * currently supported.
    */
    @property (nonatomic,strong,nullable) NSArray* CCInfo;
    /**
    * an array of payment objects @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSArray* payments;
    /**
    * an array of refund objects @readonly
    */
    @property (nonatomic,strong,nullable,readonly) NSArray* refunds;
    /**
    * payment/refund break up
    */
    @property (nonatomic,strong,nullable) NSDecimalNumber* paidAmount;
    /**
    * indicates whether or not the amount paid was done
 * so via PayPal
    */
    @property (nonatomic,assign) BOOL paidAmountIsPayPal;
    /**
    * payment/refund break up
    */
    @property (nonatomic,strong,nullable) NSDecimalNumber* refundedAmount;
    /**
    * indicates whether or not the amount refunded
 * was done so via PayPal
    */
    @property (nonatomic,assign) BOOL refundedAmountIsPayPal;
    /**
    * URI of the invoice resource.
    */
    @property (nonatomic,strong,nullable) NSString* uri;
    /**
    * Full URL of an external image to use as the logo.
 * 4000 characters max.
    */
    @property (nonatomic,strong,nullable) NSString* logoURL;
    /**
    * Any miscellaneous invoice data. 4000 characters max.
    */
    @property (nonatomic,strong,nullable) NSString* additionalData;
    /**
    * Custom amount applied on an invoice. If a label
 * is included then the amount cannot be empty.
    */
    @property (nonatomic,strong,nullable) PPRetailInvoiceCustomAmount* custom;
    /**
    * Audit information of the resource. @readonly
    */
    @property (nonatomic,strong,nullable,readonly) PPRetailInvoiceMetaData* metadata;
    /**
    * If true, this invoice was deleted from the server.
    */
    @property (nonatomic,assign) BOOL wasDeleted;
    /**
    * List of files attached to the invoice.
    */
    @property (nonatomic,strong,nullable) NSArray* attachments;
    /**
    * Unique identifier id of the template.
    */
    @property (nonatomic,strong,nullable) NSString* templateID;

    - (instancetype _Nullable)initWithCurrencyCode:(NSString* _Nullable)currencyCode;
    


    /**
     * Create a new invoice based on an existing invoice as a template.
     */
    +(PPRetailInvoice* _Nullable)withInvoice:(PPRetailInvoice* _Nullable)invoice;



    /**
     * Create a true copy of an invoice.
     */
    -(PPRetailInvoice* _Nullable)copy;

    /**
     * Adds the specified item to the invoice. If there is an existing matching item
     * on the invoice, we will increment the quantity by the quantity argument.
     * You may pass a negative quantity value to decrement the quantity of an existing item.
     */
    -(PPRetailInvoiceItem* _Nullable)addItem:(NSString* _Nullable)name quantity:(NSDecimalNumber* _Nullable)quantity unitPrice:(NSDecimalNumber* _Nullable)unitPrice itemId:(NSString* _Nullable)itemId detailId:(NSString* _Nullable)detailId;

    /**
     * Remove all items on the invoice
     */
    -(void)removeAllItems;

    /**
     * Remove an item by instance
     */
    -(BOOL)removeItem:(PPRetailInvoiceItem* _Nullable)item;

    /**
     * Find the InvoiceItem with the specified id and/or detailId
     */
    -(PPRetailInvoiceItem* _Nullable)findItem:(NSString* _Nullable)itemId detailId:(NSString* _Nullable)detailId;

    /**
     * Get an item by 0-based index
     */
    -(PPRetailInvoiceItem* _Nullable)getItem:(int)itemIndex;

    /**
     * Update the full invoice from the server, based on its payPalId.
     */
    -(void)getDetails:(PPRetailInvoiceGotDetailsHandler _Nullable)callback;

    /**
     * Save the invoice to the PayPal servers.
     */
    -(void)save:(PPRetailInvoiceSavedHandler _Nullable)callback;

    /**
     * Send the invoice. It must have already been saved to the server.
     */
    -(void)send:(BOOL)shouldNotifyMerchant callback:(PPRetailInvoiceSentHandler _Nullable)callback;

    /**
     * Delete the invoice from the server. It must have already been saved to the server.
     */
    -(void)deleteFromServer:(PPRetailInvoiceDeletedHandler _Nullable)callback;

    /**
     * Send a reminder about this invoice to its intended recipient
     */
    -(void)remind:(PPRetailInvoiceNotification* _Nullable)notification callback:(PPRetailInvoiceRemindedHandler _Nullable)callback;

    /**
     * Cancel this invoice
     */
    -(void)cancel:(PPRetailInvoiceNotification* _Nullable)notification callback:(PPRetailInvoiceCancelledHandler _Nullable)callback;

    -(void)recordPayment:(PPRetailInvoicePayment* _Nullable)paymentInfo callback:(PPRetailInvoicePaidHandler _Nullable)callback;

    -(void)recordRefund:(PPRetailInvoiceRefund* _Nullable)refundInfo callback:(PPRetailInvoicePaidHandler _Nullable)callback;




@end