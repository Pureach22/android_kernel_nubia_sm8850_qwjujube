__int64 __fastcall debug_soc_end_addr_get(__int64 *a1, _QWORD *a2)
{
  __int64 v3; // x8
  __int64 v4; // x2
  __int64 v5; // x8
  _DWORD *v6; // x8
  __int64 result; // x0
  __int64 v8; // [xsp+8h] [xbp-68h] BYREF
  __int64 v9; // [xsp+10h] [xbp-60h]
  __int64 v10; // [xsp+18h] [xbp-58h]
  __int64 v11; // [xsp+20h] [xbp-50h]
  __int64 v12; // [xsp+28h] [xbp-48h]
  __int64 v13; // [xsp+30h] [xbp-40h]
  __int64 v14; // [xsp+38h] [xbp-38h]
  __int64 v15; // [xsp+40h] [xbp-30h]
  __int64 v16; // [xsp+48h] [xbp-28h]
  __int64 v17; // [xsp+50h] [xbp-20h]
  __int64 v18; // [xsp+58h] [xbp-18h]
  __int64 v19; // [xsp+60h] [xbp-10h]
  __int64 v20; // [xsp+68h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v18 = 0;
  v19 = 0;
  v4 = *((unsigned int *)a1 + 46);
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v5 = *(_QWORD *)(v3 + 56);
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v6 = *(_DWORD **)(v5 + 112);
  v8 = 0;
  v9 = 0;
  if ( *(v6 - 1) != 364718830 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64 *, _QWORD, __int64, __int64 *))v6)(a1, WORD1(v4) & 0x1F, v4, &v8);
  if ( !(_DWORD)result )
    *a2 = v9;
  _ReadStatusReg(SP_EL0);
  return result;
}
