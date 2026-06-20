__int64 __fastcall ipa_data_path_disable(__int64 *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  char v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 1;
  if ( a1 != qword_130 )
    ipc_log_string(a1[130], "%s: Disable eps", "ipa_data_path_disable");
  if ( *a1 )
    usb_gsi_ep_op(*a1, a1 + 2, 13);
  v2 = a1[1];
  if ( v2 )
    usb_gsi_ep_op(v2, a1 + 13, 13);
  result = *a1;
  if ( *a1 )
    result = usb_gsi_ep_op(result, v4, 11);
  _ReadStatusReg(SP_EL0);
  return result;
}
