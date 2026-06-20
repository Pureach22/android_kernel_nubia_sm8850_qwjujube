__int64 __fastcall cam_ife_csid_ver2_rx2_top_half(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v3; // w22
  unsigned int v4; // w20
  __int64 v5; // x21
  bool v6; // cc
  __int64 result; // x0
  __int64 v8; // x0
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a2;
  v9 = 0;
  if ( v2 )
  {
    v3 = **(_DWORD **)(a2 + 16);
    if ( !v3 )
    {
LABEL_12:
      result = 0;
      goto LABEL_17;
    }
    v4 = 0;
    v5 = *(_QWORD *)(**(_QWORD **)(v2 + 31136) + 128LL);
    do
    {
      if ( (v3 & 1) != 0 && (((unsigned __int64)*(unsigned int *)(v2 + 2196) >> v4) & 1) != 0 )
        cam_ife_csid_ver2_handle_rx_debug_event(v2, 1u, v4, &v9);
      v6 = v3 > 1;
      ++v4;
      v3 >>= 1;
    }
    while ( v6 );
    result = v9;
    if ( v9 )
    {
      if ( *(_DWORD *)(v2 + 2180) )
        cam_io_w_mb(v9, *(_QWORD *)(*(_QWORD *)(v2 + 31128) + 384LL) + *(unsigned int *)(v5 + 44));
      goto LABEL_12;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_rx2_top_half__rs, "cam_ife_csid_ver2_rx2_top_half") )
      v8 = 3;
    else
      v8 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v8,
      8,
      1,
      "cam_ife_csid_ver2_rx2_top_half",
      1866,
      "No private returned");
    result = 4294967277LL;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
