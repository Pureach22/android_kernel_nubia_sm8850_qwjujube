__int64 __fastcall lim_send_sme_tsm_ie_ind(__int64 result, __int64 a2, char a3, char a4, __int16 a5)
{
  __int64 v7; // x19
  char v10; // w8
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
  if ( result )
  {
    if ( a2 )
    {
      v7 = result;
      result = _qdf_mem_malloc(6u, "lim_send_sme_tsm_ie_ind", 4893);
      if ( result )
      {
        v10 = *(_BYTE *)(a2 + 10);
        *(_BYTE *)result = a3;
        *(_BYTE *)(result + 1) = a4;
        *(_BYTE *)(result + 4) = v10;
        *(_WORD *)(result + 2) = a5;
        v12 = result;
        LOWORD(v11) = 5202;
        HIDWORD(v11) = 0;
        result = sys_process_mmh_msg(v7, &v11);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
