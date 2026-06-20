__int64 __fastcall lim_nss_or_ch_width_update_rsp(__int64 a1, char a2, int a3, int a4)
{
  __int64 v7; // x0
  __int64 v8; // x19
  __int16 v9; // w8
  __int64 result; // x0
  __int64 v11; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+10h] [xbp-30h]
  __int64 v13; // [xsp+18h] [xbp-28h]
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v7 = _qdf_mem_malloc(0xCu, "lim_nss_or_ch_width_update_rsp", 2964);
  v8 = v7;
  if ( v7 )
  {
    *(_BYTE *)v7 = a2;
    *(_DWORD *)(v7 + 4) = a4;
    *(_DWORD *)(v7 + 8) = a3;
  }
  if ( a4 == 1 )
  {
    v9 = 5229;
  }
  else
  {
    if ( a4 != 8 )
    {
LABEL_8:
      result = _qdf_mem_free(v8);
      goto LABEL_9;
    }
    v9 = 5170;
  }
  LOWORD(v11) = v9;
  v12 = v7;
  HIDWORD(v11) = 0;
  result = scheduler_post_message_debug(
             0x35u,
             0x34u,
             52,
             (unsigned __int16 *)&v11,
             0xBA5u,
             (__int64)"lim_nss_or_ch_width_update_rsp");
  if ( (_DWORD)result )
    goto LABEL_8;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
