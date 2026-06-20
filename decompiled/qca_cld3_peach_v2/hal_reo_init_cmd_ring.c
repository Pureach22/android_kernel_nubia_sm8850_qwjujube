__int64 __fastcall hal_reo_init_cmd_ring(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 srng_params; // x0
  __int64 v5; // x21
  unsigned __int8 (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x22
  __int64 result; // x0
  int v9; // w8
  __int64 v10; // x10
  int v11; // w9
  __int64 v12; // [xsp+0h] [xbp-60h] BYREF
  __int64 v13; // [xsp+8h] [xbp-58h]
  __int64 v14; // [xsp+10h] [xbp-50h]
  __int64 v15; // [xsp+18h] [xbp-48h]
  __int64 v16; // [xsp+20h] [xbp-40h]
  __int64 v17; // [xsp+28h] [xbp-38h]
  __int64 v18; // [xsp+30h] [xbp-30h]
  __int64 v19; // [xsp+38h] [xbp-28h]
  __int64 v20; // [xsp+40h] [xbp-20h]
  __int64 v21; // [xsp+48h] [xbp-18h]
  __int64 v22; // [xsp+50h] [xbp-10h]
  __int64 v23; // [xsp+58h] [xbp-8h]

  v3 = a1 + 73728;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 0;
  srng_params = hal_get_srng_params(a1, a2, &v12);
  v5 = v13;
  v6 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 664) + 1664LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != 799902358 )
      __break(0x8228u);
    v7 = v6(srng_params) >> 2;
  }
  else
  {
    v7 = 0;
  }
  result = hal_srng_get_entrysize(a1, 3);
  v9 = v14;
  if ( (_DWORD)v14 )
  {
    v10 = v5 + 4 * v7;
    v11 = 0;
    do
    {
      *(_DWORD *)v10 = ++v11 | (*(unsigned __int16 *)(v10 + 2) << 16);
      v10 += (unsigned int)result & 0xFFFFFFFC;
    }
    while ( v9 != v11 );
  }
  *(_BYTE *)(v3 + 320) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
