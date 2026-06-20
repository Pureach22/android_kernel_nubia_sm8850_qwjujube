__int64 __fastcall qcedev_check_extended_cipher_params(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  __int64 v4; // x2
  unsigned __int64 v5; // x4
  unsigned int v6; // w8
  unsigned int v7; // w8
  unsigned int v8; // w8
  __int64 v9; // x9
  __int64 v10; // x12
  __int64 v11; // x8
  _QWORD *v12; // x10
  unsigned __int64 v13; // x9
  __int64 v14; // x9
  unsigned int v15; // w8
  _QWORD *v16; // x10
  void *v18; // x0
  void *v19; // x0
  const char *v20; // x1

  v4 = *(unsigned int *)(a1 + 512);
  if ( !(_DWORD)v4 || (unsigned int)v4 > 0x10 || (v5 = *(_QWORD *)(a1 + 656)) == 0 )
  {
    v18 = &unk_1204D;
LABEL_43:
    printk(v18, "qcedev_check_extended_cipher_params", v4, a4);
    return 4294967274LL;
  }
  v6 = *(_DWORD *)(a1 + 744);
  a4 = *(unsigned int *)(a1 + 748);
  if ( v6 != 2 || (unsigned int)a4 >= 3 )
  {
    printk(&unk_122BB, "qcedev_check_extended_cipher_params", v6, a4);
    return 4294967274LL;
  }
  if ( !*(_DWORD *)(a1 + 668) )
    return 4294967274LL;
  v7 = *(_DWORD *)(a1 + 664);
  if ( !v7 )
    return 4294967274LL;
  if ( v7 != 16 && v7 != 32 )
  {
    v19 = &unk_12D23;
    v20 = "qcedev_check_offload_key";
    goto LABEL_47;
  }
  v8 = *(unsigned __int8 *)(a1 + 520);
  if ( *(_BYTE *)(a1 + 520) )
  {
    if ( (_DWORD)a4 == 2 )
    {
      if ( v8 < 0x10 )
      {
        v9 = 0;
        while ( v9 != 256 )
        {
          v10 = *(_QWORD *)(a1 + v9);
          if ( v8 > (unsigned __int64)(0xFFFFFFFFLL - v10) )
          {
            v18 = &unk_11CBD;
            goto LABEL_43;
          }
          v9 += 16;
          v8 += v10;
          if ( 16 * v4 == v9 )
            goto LABEL_17;
        }
        goto LABEL_49;
      }
      v18 = &unk_12175;
    }
    else
    {
      v18 = &unk_118E0;
    }
    goto LABEL_43;
  }
LABEL_17:
  v7 = *(_DWORD *)(a1 + 536);
  if ( v7 > 0x20 )
  {
    v19 = &unk_1190E;
    v20 = "qcedev_check_extended_cipher_params";
LABEL_47:
    printk(v19, v20, v7, a4);
    return 4294967274LL;
  }
  v11 = 0;
  a4 = 0;
  v12 = (_QWORD *)(a1 + 264);
  while ( v11 != 16 )
  {
    v13 = *(v12 - 1);
    if ( !*v12 && v13 )
    {
      v18 = &unk_1248E;
      v4 = (unsigned int)v11;
      a4 = *(v12 - 1);
      goto LABEL_43;
    }
    if ( v13 >= (unsigned int)~(_DWORD)a4 )
    {
      v18 = &unk_12C14;
      goto LABEL_43;
    }
    ++v11;
    a4 = (unsigned int)(a4 + v13);
    v12 += 2;
    if ( v4 == v11 )
    {
      if ( v5 != (unsigned int)a4 )
      {
        printk(&unk_11BD3, "qcedev_check_extended_cipher_params", v4, a4);
        return 4294967274LL;
      }
      v14 = 0;
      v15 = 0;
      v16 = (_QWORD *)(a1 + 8);
      while ( v14 != 16 )
      {
        a4 = *(v16 - 1);
        if ( !*v16 && a4 )
        {
          v18 = &unk_12072;
          v4 = (unsigned int)v14;
          goto LABEL_43;
        }
        if ( a4 > ~v15 )
        {
          v18 = &unk_11DCA;
          goto LABEL_43;
        }
        ++v14;
        v15 += a4;
        v16 += 2;
        if ( v4 == v14 )
        {
          if ( v5 == v15 )
            return 0;
          v18 = &unk_11CE1;
          v4 = v15;
          a4 = v5;
          goto LABEL_43;
        }
      }
      break;
    }
  }
LABEL_49:
  __break(0x5512u);
  return qcedev_smmu_ablk_offload_cipher(a1, a2);
}
