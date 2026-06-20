__int64 __fastcall gh_rm_ipa_reserve(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        unsigned int a6,
        _QWORD *a7)
{
  __int64 v7; // x9
  unsigned int v8; // w19
  unsigned int v10; // w0
  __int64 v11; // x0
  __int64 v13; // [xsp+8h] [xbp-48h] BYREF
  __int64 v14; // [xsp+10h] [xbp-40h] BYREF
  char v15; // [xsp+18h] [xbp-38h] BYREF
  __int16 v16; // [xsp+19h] [xbp-37h]
  char v17; // [xsp+1Bh] [xbp-35h]
  int v18; // [xsp+1Ch] [xbp-34h]
  unsigned int v19; // [xsp+20h] [xbp-30h]
  int v20; // [xsp+24h] [xbp-2Ch]
  __int64 v21; // [xsp+28h] [xbp-28h]
  __int64 v22; // [xsp+30h] [xbp-20h]
  __int64 v23; // [xsp+38h] [xbp-18h]
  __int64 v24; // [xsp+40h] [xbp-10h]
  __int64 v25; // [xsp+48h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v16 = 0;
  if ( gh_rm_core_initialized == 1 )
  {
    v7 = -4096;
    v8 = -22;
    if ( a4 - a3 != -1 )
      v7 = a4 - a3 + 1;
    if ( (a5 & 0xFFFFFFB0) == 0
      && a6 <= 7
      && (((unsigned __int16)a2 | (unsigned __int16)a1) & 0xFFF) == 0
      && (a3 & 0xFFF) == 0
      && (v7 & 0xFFF) == 0 )
    {
      v23 = a1;
      v24 = a2;
      v15 = 1;
      v20 = 1;
      v18 = a5;
      v19 = a6;
      v21 = a3;
      v22 = v7;
      v13 = 0;
      v14 = 0;
      v10 = gunyah_rm_call(rm, 1442840752, &v15, 48, &v14, &v13);
      if ( v10 )
      {
        v8 = v10;
        printk(&unk_12082, "gh_rm_ipa_reserve");
      }
      else if ( v13 == 12 )
      {
        v11 = v14;
        *a7 = *(_QWORD *)(v14 + 4);
        kfree(v11);
        v8 = 0;
      }
      else
      {
        printk(&unk_1372E, "gh_rm_ipa_reserve");
        if ( v13 )
          kfree(v14);
        v8 = -22;
      }
    }
  }
  else
  {
    v8 = -517;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
