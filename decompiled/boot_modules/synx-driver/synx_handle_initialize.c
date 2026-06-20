__int64 __fastcall synx_handle_initialize(
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
  unsigned __int64 v10; // x0
  __int64 v11; // x5
  _QWORD v12[3]; // [xsp+0h] [xbp-70h] BYREF
  _QWORD v13[8]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v14; // [xsp+58h] [xbp-18h]
  int v15; // [xsp+60h] [xbp-10h]
  __int64 v16; // [xsp+68h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a1 + 4);
  v12[1] = 0;
  if ( v6 != 76 )
    goto LABEL_14;
  v7 = *a2;
  v15 = 0;
  v14 = 0;
  memset(v13, 0, sizeof(v13));
  if ( !v7 || v7 > 0xFFFFFFFFFFFFF000LL )
  {
    if ( inline_copy_from_user((int)v13, *(_QWORD *)(a1 + 16), 0x4Cu) )
    {
      result = 4294967282LL;
      goto LABEL_15;
    }
    v12[0] = v13;
    v12[2] = v14;
    v10 = synx_initialize(v12);
    *a2 = v10;
    if ( v10 && v10 < 0xFFFFFFFFFFFFF001LL )
    {
      result = 0;
      goto LABEL_15;
    }
    if ( (synx_debug & 1) != 0 )
      printk(&unk_26F27, &unk_29207, "synx_handle_initialize", 2747, v10, v11);
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_26324, &unk_29207, "synx_handle_initialize", 2732, v7, a6);
  result = 4294967182LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
