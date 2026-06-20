__int64 __fastcall synx_handle_initialize_v3(
        __int64 a1,
        unsigned __int64 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  int v6; // w8
  unsigned __int64 v7; // x4
  __int64 result; // x0
  unsigned __int64 v11; // x0
  __int64 v12; // x5
  __int64 v13; // x8
  __int64 v14; // x19
  unsigned __int64 v15; // x20
  _QWORD v16[2]; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v17; // [xsp+10h] [xbp-B0h]
  __int64 v18; // [xsp+18h] [xbp-A8h]
  __int64 v19; // [xsp+20h] [xbp-A0h]
  __int64 v20; // [xsp+28h] [xbp-98h]
  _QWORD v21[3]; // [xsp+30h] [xbp-90h] BYREF
  _QWORD v22[8]; // [xsp+48h] [xbp-78h] BYREF
  __int64 v23; // [xsp+88h] [xbp-38h]
  __int64 v24; // [xsp+90h] [xbp-30h]
  __int64 v25; // [xsp+98h] [xbp-28h]
  __int64 v26; // [xsp+A0h] [xbp-20h]
  __int64 v27; // [xsp+A8h] [xbp-18h]
  __int64 v28; // [xsp+B0h] [xbp-10h]
  __int64 v29; // [xsp+B8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a1 + 4);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v16[0] = 0;
  v16[1] = 0;
  if ( v6 != 112 )
    goto LABEL_20;
  v7 = *a2;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  memset(v22, 0, sizeof(v22));
  if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_26324, &unk_29207, "synx_handle_initialize_v3", 2765, v7, a6);
    result = 4294967182LL;
    goto LABEL_21;
  }
  if ( inline_copy_from_user((int)v22, *(_QWORD *)(a1 + 16), 0x70u) )
  {
    result = 4294967282LL;
    goto LABEL_21;
  }
  v21[2] = v23;
  v21[0] = v22;
  v21[1] = v16;
  if ( (_DWORD)v24 )
  {
LABEL_20:
    result = 4294967274LL;
    goto LABEL_21;
  }
  v11 = synx_initialize(v21);
  *a2 = v11;
  if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_26F27, &unk_29207, "synx_handle_initialize_v3", 2784, v11, v12);
    goto LABEL_20;
  }
  if ( !(_DWORD)v24 )
  {
    v25 = v17;
    v26 = v19;
    v27 = v20;
  }
  v13 = a1;
  v14 = *(unsigned int *)(a1 + 4);
  if ( (unsigned int)v14 >= 0x71 )
  {
    _copy_overflow(112, v14);
    result = 4294967282LL;
  }
  else
  {
    v15 = *(_QWORD *)(v13 + 16);
    _check_object_size(v22, v14, 1);
    if ( inline_copy_to_user(v15, (__int64)v22, v14) )
      result = 4294967282LL;
    else
      result = 0;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
