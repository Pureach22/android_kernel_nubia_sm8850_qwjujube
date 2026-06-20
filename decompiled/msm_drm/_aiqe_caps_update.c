__int64 __fastcall aiqe_caps_update(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  __int64 v6; // x8
  unsigned int v7; // w9
  bool v8; // cf
  __int64 v9; // x23
  unsigned int v10; // w3
  __int64 v11; // x25
  __int64 v12; // x8
  unsigned int v13; // w26
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v15; // [xsp+10h] [xbp-100h]
  __int64 v16; // [xsp+18h] [xbp-F8h]
  __int64 v17; // [xsp+20h] [xbp-F0h]
  __int64 v18; // [xsp+28h] [xbp-E8h]
  __int64 v19; // [xsp+30h] [xbp-E0h]
  __int64 v20; // [xsp+38h] [xbp-D8h]
  __int64 v21; // [xsp+40h] [xbp-D0h]
  __int64 v22; // [xsp+48h] [xbp-C8h]
  __int64 v23; // [xsp+50h] [xbp-C0h]
  __int64 v24; // [xsp+58h] [xbp-B8h]
  __int64 v25; // [xsp+60h] [xbp-B0h]
  __int64 v26; // [xsp+68h] [xbp-A8h]
  __int64 v27; // [xsp+70h] [xbp-A0h]
  __int64 v28; // [xsp+78h] [xbp-98h]
  __int64 v29; // [xsp+80h] [xbp-90h]
  __int64 v30; // [xsp+88h] [xbp-88h]
  __int64 v31; // [xsp+90h] [xbp-80h]
  __int64 v32; // [xsp+98h] [xbp-78h]
  __int64 v33; // [xsp+A0h] [xbp-70h]
  __int64 v34; // [xsp+A8h] [xbp-68h]
  __int64 v35; // [xsp+B0h] [xbp-60h]
  __int64 v36; // [xsp+B8h] [xbp-58h]
  __int64 v37; // [xsp+C0h] [xbp-50h]
  __int64 v38; // [xsp+C8h] [xbp-48h]
  __int64 v39; // [xsp+D0h] [xbp-40h]
  __int64 v40; // [xsp+D8h] [xbp-38h]
  __int64 v41; // [xsp+E0h] [xbp-30h]
  __int64 v42; // [xsp+E8h] [xbp-28h]
  __int64 v43; // [xsp+F0h] [xbp-20h]
  __int64 v44; // [xsp+F8h] [xbp-18h]
  __int64 v45; // [xsp+100h] [xbp-10h]
  __int64 v46; // [xsp+108h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = get_kms(a1);
  v5 = *(_QWORD *)(result + 152);
  v6 = *(unsigned int *)(a1 + 2192);
  v7 = *(_DWORD *)(v5 + 20104);
  if ( v7 )
    v8 = (int)v6 - 1 >= v7;
  else
    v8 = 1;
  if ( !v8 )
  {
    v9 = 0;
    v10 = 0;
    v11 = 48 * v6;
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    v18 = 0;
    v19 = 0;
    v16 = 0;
    v17 = 0;
    *(_QWORD *)s = 0;
    v15 = 0;
    do
    {
      if ( v9 == 384 )
        __break(0x5512u);
      if ( v10 >= *(_DWORD *)(v5 + 20104) )
        break;
      v12 = *(_QWORD *)(a1 + 2216 + v9);
      if ( v12 && *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 72) + 48LL) + 604LL) )
      {
        v13 = v10 + 1;
        snprintf(s, 0x100u, "aiqe%u", v10);
        result = sde_kms_info_add_keyint(a2, (__int64)s, 1);
        v10 = v13;
      }
      v9 += 48;
    }
    while ( v11 != v9 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
