__int64 __fastcall dp_link_send_edid_checksum(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = a2;
  if ( a1 )
  {
    result = drm_dp_dpcd_write(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 24LL), 609, v4, 1);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = printk(&unk_275B6D, "dp_link_send_edid_checksum");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
