__int64 __fastcall ipa_init_ep_flt_bitmap(__int64 result)
{
  __int64 v1; // x13
  __int64 v2; // x8
  unsigned __int8 *v3; // x9
  __int64 v4; // x0
  _BYTE *v5; // x14
  __int64 v6; // x11
  __int64 v7; // x10
  unsigned __int64 v8; // x16
  unsigned int v9; // w1
  __int64 v10; // x1
  int v11; // w11

  v2 = ipa3_ctx;
  v3 = (unsigned __int8 *)(ipa3_ctx + 32244);
  if ( *(_QWORD *)(ipa3_ctx + 17488) )
  {
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d EP Filter bitmap is already initialized\n", "ipa_init_ep_flt_bitmap", 8633);
        v2 = ipa3_ctx;
      }
      result = *(_QWORD *)(v2 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d EP Filter bitmap is already initialized\n",
                 "ipa_init_ep_flt_bitmap",
                 8633);
    }
  }
  else
  {
    if ( *v3 <= 0x17uLL )
    {
      v5 = &ipa3_ep_mapping[6968 * *v3];
      v6 = 0;
      v7 = 0;
      v1 = 0;
      v8 = 6968LL * *v3 - 167224;
      result = 26;
      while ( v8 >= 0xFFFFFFFFFFFD72C0LL )
      {
        if ( (v5[8] & 1) != 0 )
        {
          if ( (v7 & 0xFE) != 0x3E && (v7 & 0xF8) != 0x40
            || (v9 = *((_DWORD *)v3 + 1), v9 <= 4) && ((1 << v9) & 0x1A) != 0 )
          {
            if ( v8 + 12 < 0xFFFFFFFFFFFD72C0LL )
              break;
            v10 = (1LL << *((_DWORD *)v5 + 5)) | v1;
            v1 = v6;
            if ( v10 != v6 )
            {
              v11 = *(_DWORD *)(v2 + 17496);
              v1 = v10;
              *(_QWORD *)(v2 + 17488) = v10;
              *(_DWORD *)(v2 + 17496) = v11 + 1;
              v6 = v10;
            }
          }
        }
        ++v7;
        v8 += 52LL;
        v5 += 52;
        if ( v7 == 134 )
          return result;
      }
      __break(1u);
    }
    __break(0x5512u);
    if ( (v1 & 0x1000000) != 0 )
      JUMPOUT(0x11FB54);
    return ipa_is_ep_support_flt(result);
  }
  return result;
}
