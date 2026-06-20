__int64 __fastcall dp_srng_access_start(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x19
  char v5; // w11
  unsigned __int8 v6; // w2
  int v7; // w9
  int v8; // w8
  int v9; // w10
  bool v10; // zf
  __int64 v11; // x8
  int v12; // w11
  __int64 result; // x0
  __int64 v14; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h]
  __int64 v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 1128);
  if ( a1 )
  {
    v5 = *a3;
    v6 = *(_BYTE *)(a1 + 32);
    v7 = **((_DWORD **)a3 + 16);
    v14 = 0;
    v15 = 0;
    v8 = *((_DWORD *)a3 + 29);
    v9 = *((_DWORD *)a3 + 30);
    LOBYTE(v14) = v5;
    v16 = 0;
    v17 = 0;
    v10 = v8 == 0;
    v11 = *(_QWORD *)(a2 + 64);
    if ( v10 )
      v12 = v9;
    else
      v12 = v7;
    if ( !v10 )
      v7 = v9;
    HIDWORD(v14) = v12;
    LODWORD(v15) = v7;
    LODWORD(v17) = 4;
    hif_hist_record_event(v11, (__int64)&v14, v6);
  }
  result = dp_hal_srng_access_start(v4, a3);
  _ReadStatusReg(SP_EL0);
  return result;
}
