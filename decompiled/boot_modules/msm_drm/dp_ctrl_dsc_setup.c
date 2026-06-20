__int64 __fastcall dp_ctrl_dsc_setup(__int64 result, __int64 a2)
{
  int v2; // w8
  char v3; // w19
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 ipc_log_context; // x0
  _BYTE v7[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(result + 259);
  v7[0] = 0;
  if ( v2 == 1 )
  {
    v3 = *(_BYTE *)(a2 + 168);
    if ( *(_BYTE *)(result + 258) != 1
      || (*(_DWORD *)(a2 + 912) != 1 || *(_BYTE *)(a2 + 168))
      && (!*(_BYTE *)(a2 + 168)
       || *(_DWORD *)(result + 276) < 2u
       || (v4 = result,
           drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(result + 136) + 24LL), 352, v7, 1),
           result = v4,
           (v7[0] & 1) == 0)) )
    {
      v5 = *(_QWORD *)(result + 136);
      v8[0] = v3;
      result = drm_dp_dpcd_write(*(_QWORD *)(v5 + 24), 352, v8, 1);
      if ( (int)result <= 0 )
      {
        ipc_log_context = get_ipc_log_context(result);
        ipc_log_string(
          ipc_log_context,
          "[w][%-4d]failed to enable sink dsc\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        result = printk(&unk_26F365, "dp_ctrl_dsc_setup");
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
