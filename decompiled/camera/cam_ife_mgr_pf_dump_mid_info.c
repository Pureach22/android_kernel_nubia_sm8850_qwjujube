__int64 __fastcall cam_ife_mgr_pf_dump_mid_info(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 **v5; // x8
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x10
  int v9; // w11
  __int64 v10; // x0
  __int64 v11; // x21
  unsigned int (__fastcall *v12)(__int64, __int64, __int64 *, __int64); // x9
  __int64 result; // x0
  int v14; // w6
  int v15; // w10
  int v16; // w7
  int v17; // [xsp+10h] [xbp-50h] BYREF
  __int64 v18; // [xsp+14h] [xbp-4Ch]
  int v19; // [xsp+1Ch] [xbp-44h]
  __int64 v20; // [xsp+20h] [xbp-40h] BYREF
  __int64 v21; // [xsp+28h] [xbp-38h]
  __int64 v22; // [xsp+30h] [xbp-30h]
  __int64 v23; // [xsp+38h] [xbp-28h]
  __int64 v24; // [xsp+40h] [xbp-20h]
  int *v25; // [xsp+48h] [xbp-18h]
  __int64 v26; // [xsp+50h] [xbp-10h]
  __int64 v27; // [xsp+58h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(__int64 ***)(a2 + 16);
  v25 = nullptr;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  v6 = **v5;
  v7 = *v5[1];
  LODWORD(v21) = 38;
  v8 = *a3;
  v9 = *(_DWORD *)(v6 + 52);
  v10 = *(_QWORD *)(*a3 + 112);
  v11 = *(_QWORD *)(v7 + 136);
  HIDWORD(v18) = *(_DWORD *)(v6 + 48);
  v12 = *(unsigned int (__fastcall **)(__int64, __int64, __int64 *, __int64))(v8 + 88);
  v17 = v9;
  v25 = &v17;
  if ( *((_DWORD *)v12 - 1) != -1055839300 )
    __break(0x8229u);
  if ( v12(v10, 38, &v20, 56) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_pf_dump_mid_info",
      15975,
      "getting mid port resource id failed ctx id:%u req id:%lld",
      *(_DWORD *)(a1 + 56),
      *(_QWORD *)(v11 + 8));
    result = 0;
  }
  else
  {
    v15 = v17;
    v14 = v18;
    *(_DWORD *)(**(_QWORD **)(a2 + 16) + 12LL) = v18;
    *(_BYTE *)(a1 + 9383) = 1;
    v16 = *(_DWORD *)(a1 + 56);
    *(_DWORD *)(a1 + 9408) = v15;
    *(_DWORD *)(a1 + 9404) = v14;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_pf_dump_mid_info",
      15985,
      "Page fault on resource id:(0x%x) ctx id:%u req id:%lld",
      v14,
      v16,
      *(_QWORD *)(v11 + 8));
    result = (unsigned __int8)v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
