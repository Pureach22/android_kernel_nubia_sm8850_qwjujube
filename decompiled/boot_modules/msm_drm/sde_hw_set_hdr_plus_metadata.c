__int64 __fastcall sde_hw_set_hdr_plus_metadata(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  bool v5; // cf
  unsigned int v6; // w2
  char v7; // w8
  __int64 v10; // x8
  bool v11; // zf
  int v12; // w10
  int v13; // w11
  int v14; // w8
  int v15; // w9
  unsigned int v16; // w22
  unsigned int v17; // w1
  __int64 result; // x0
  unsigned int v19; // w25
  unsigned int v20; // w8
  __int64 v21; // x8
  unsigned int v22; // w2

  v5 = a3 != 0;
  v6 = a3 - 1;
  v7 = v5;
  if ( !a2 || (v7 & 1) == 0 )
    return printk(&unk_21351A, "sde_hw_set_hdr_plus_metadata");
  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL);
  if ( a4 )
  {
    if ( (v10 & 0x200) != 0 )
    {
      v17 = 8204;
      v16 = 8196;
      goto LABEL_19;
    }
    v11 = (*(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x400LL) == 0;
    v12 = 1757196;
    v13 = 1152;
    v14 = 1757188;
    v15 = 1136;
  }
  else
  {
    if ( (v10 & 0x200) != 0 )
    {
      v17 = 4108;
      v16 = 4100;
      goto LABEL_19;
    }
    v11 = (*(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x400LL) == 0;
    v15 = 1132;
    v14 = 1753092;
    v13 = 1148;
    v12 = 1753100;
  }
  if ( v11 )
    v16 = v15;
  else
    v16 = v14;
  if ( v11 )
    v17 = v13;
  else
    v17 = v12;
LABEL_19:
  result = sde_reg_write(a1, v17, v6, "nb_offset");
  if ( a3 >= 2 )
  {
    v19 = 4;
    do
    {
      v21 = v19 - 3;
      v22 = *(unsigned __int8 *)(a2 + v21);
      if ( v21 + 1 < (unsigned __int64)a3 )
      {
        v22 |= *(unsigned __int8 *)(a2 + v19 - 2) << 8;
        if ( v21 + 2 < (unsigned __int64)a3 )
        {
          v22 |= *(unsigned __int8 *)(a2 + v19 - 1) << 16;
          if ( v21 + 3 < (unsigned __int64)a3 )
            v22 |= *(unsigned __int8 *)(a2 + v19) << 24;
        }
      }
      result = sde_reg_write(a1, v16, v22, "d_offset");
      v20 = v19 + 1;
      v19 += 4;
    }
    while ( v20 < a3 );
  }
  return result;
}
