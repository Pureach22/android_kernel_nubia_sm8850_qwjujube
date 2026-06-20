__int64 __usercall aw_dev_set_channal_mode@<X0>(_QWORD *a1@<X0>, __int64 a2@<X1>, unsigned int a3@<W2>, int _W8@<W8>)
{
  __int64 v4; // x8
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // t2
  __int64 (__fastcall *v10)(__int64, __int64, __int64, __int64); // x9
  __int64 v11; // x3
  unsigned int v12; // w0
  __int64 *v14; // x8
  unsigned int v15; // w20
  __int64 v16; // x1

  if ( a3 >= 4 )
  {
    __break(0x5512u);
    __asm { STLLR           W8, [X9] }
    JUMPOUT(0x21714);
  }
  v4 = a2 + 2LL * a3;
  v6 = a1[15];
  v9 = a2 + 12;
  v7 = *(unsigned int *)(a2 + 12);
  v8 = *(unsigned int *)(v9 + 4);
  v10 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64))a1[146];
  v11 = *(unsigned __int16 *)(v4 + 4);
  if ( *((_DWORD *)v10 - 1) != 370515439 )
    __break(0x8229u);
  v12 = v10(v6, v7, v8, v11);
  if ( (v12 & 0x80000000) == 0 )
    return 0;
  v14 = (__int64 *)a1[14];
  v15 = v12;
  v16 = v14[14];
  if ( !v16 )
    v16 = *v14;
  printk(&unk_258B8, v16, "aw_dev_set_channal_mode");
  return v15;
}
