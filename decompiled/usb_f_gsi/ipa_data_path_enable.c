__int64 __fastcall ipa_data_path_enable(_QWORD *a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x0
  __int64 result; // x0
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v2 = a1 - 38;
  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  if ( a1 != qword_130 )
    ipc_log_string(a1[130], "IN: db_reg_phs_addr_lsb = %x", *((_DWORD *)a1 + 12));
  usb_gsi_ep_op(*a1, a1 + 2, 2);
  v3 = a1[1];
  if ( v3 )
  {
    if ( v2 )
    {
      ipc_log_string(a1[130], "OUT: db_reg_phs_addr_lsb = %x", *((_DWORD *)a1 + 34));
      v3 = a1[1];
    }
    usb_gsi_ep_op(v3, a1 + 13, 2);
    usb_gsi_ep_op(a1[1], a1 + 13, 3);
  }
  usb_gsi_ep_op(*a1, v5, 11);
  usb_gsi_ep_op(*a1, a1 + 2, 5);
  result = a1[1];
  if ( result )
    result = usb_gsi_ep_op(result, a1 + 13, 5);
  _ReadStatusReg(SP_EL0);
  return result;
}
