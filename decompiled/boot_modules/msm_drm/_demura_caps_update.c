unsigned int *__fastcall demura_caps_update(unsigned int *result, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x8
  unsigned int v4; // w9
  bool v5; // cf
  unsigned __int64 v7; // x23
  unsigned int *v8; // x24
  __int64 v9; // x25
  __int64 v10; // x8
  unsigned int v11; // w3
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v13; // [xsp+10h] [xbp-100h]
  __int64 v14; // [xsp+18h] [xbp-F8h]
  __int64 v15; // [xsp+20h] [xbp-F0h]
  __int64 v16; // [xsp+28h] [xbp-E8h]
  __int64 v17; // [xsp+30h] [xbp-E0h]
  __int64 v18; // [xsp+38h] [xbp-D8h]
  __int64 v19; // [xsp+40h] [xbp-D0h]
  __int64 v20; // [xsp+48h] [xbp-C8h]
  __int64 v21; // [xsp+50h] [xbp-C0h]
  __int64 v22; // [xsp+58h] [xbp-B8h]
  __int64 v23; // [xsp+60h] [xbp-B0h]
  __int64 v24; // [xsp+68h] [xbp-A8h]
  __int64 v25; // [xsp+70h] [xbp-A0h]
  __int64 v26; // [xsp+78h] [xbp-98h]
  __int64 v27; // [xsp+80h] [xbp-90h]
  __int64 v28; // [xsp+88h] [xbp-88h]
  __int64 v29; // [xsp+90h] [xbp-80h]
  __int64 v30; // [xsp+98h] [xbp-78h]
  __int64 v31; // [xsp+A0h] [xbp-70h]
  __int64 v32; // [xsp+A8h] [xbp-68h]
  __int64 v33; // [xsp+B0h] [xbp-60h]
  __int64 v34; // [xsp+B8h] [xbp-58h]
  __int64 v35; // [xsp+C0h] [xbp-50h]
  __int64 v36; // [xsp+C8h] [xbp-48h]
  __int64 v37; // [xsp+D0h] [xbp-40h]
  __int64 v38; // [xsp+D8h] [xbp-38h]
  __int64 v39; // [xsp+E0h] [xbp-30h]
  __int64 v40; // [xsp+E8h] [xbp-28h]
  __int64 v41; // [xsp+F0h] [xbp-20h]
  __int64 v42; // [xsp+F8h] [xbp-18h]
  __int64 v43; // [xsp+100h] [xbp-10h]
  __int64 v44; // [xsp+108h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 56LL) + 8LL) + 152LL);
  v3 = result[548];
  v4 = *(_DWORD *)(v2 + 19980);
  if ( v4 )
    v5 = (int)v3 - 1 >= v4;
  else
    v5 = 1;
  if ( !v5 )
  {
    v7 = 0;
    v8 = result + 554;
    v9 = 48 * v3;
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
    v14 = 0;
    v15 = 0;
    *(_QWORD *)s = 0;
    v13 = 0;
    do
    {
      if ( v7 == 384 )
        __break(0x5512u);
      v10 = *(_QWORD *)&v8[v7 / 4];
      if ( v10 )
      {
        v11 = *(_DWORD *)(v10 + 64) - 1;
        if ( v11 < *(_DWORD *)(v2 + 19980) )
        {
          snprintf(s, 0x100u, "demura%u", v11);
          result = (unsigned int *)sde_kms_info_add_keyint(a2, (__int64)s, 1);
        }
      }
      v7 += 48LL;
    }
    while ( v9 != v7 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
