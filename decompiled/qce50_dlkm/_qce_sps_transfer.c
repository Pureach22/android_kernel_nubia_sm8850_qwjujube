__int64 __fastcall qce_sps_transfer(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x8
  unsigned int v5; // w22
  int v6; // w9
  __int64 v7; // x23
  __int64 result; // x0
  __int64 v9; // x2
  void *v10; // x8
  __int64 v11; // x19
  unsigned int v12; // w19

  if ( (unsigned int)a2 < 9 )
  {
    v3 = a1 + 7432LL * (unsigned int)a2;
    *(_BYTE *)(v3 + 2628) = 1;
    v4 = (unsigned int)a2 | 0xDEAD0000;
    v5 = *(unsigned __int16 *)(v3 + 10044);
    v6 = *(_DWORD *)(v3 + 2672);
    *(_QWORD *)(v3 + 2712) = v4;
    *(_QWORD *)(v3 + 2680) = v4;
    if ( v6 )
    {
      if ( v5 <= 5 )
      {
        v7 = a1 + 184LL * v5;
        LODWORD(result) = sps_transfer(*(_QWORD *)(v7 + 1520), v3 + 2656);
        if ( (_DWORD)result )
        {
          v9 = *(_QWORD *)(v7 + 1520);
          v10 = &unk_16292;
LABEL_9:
          v12 = result;
          printk(v10, "_qce_sps_transfer", v9);
          *(_BYTE *)(v3 + 2628) = 0;
          return v12;
        }
LABEL_7:
        v11 = a1 + 184LL * v5;
        result = sps_transfer(*(_QWORD *)(v11 + 416), v3 + 2688);
        if ( !(_DWORD)result )
          return result;
        v9 = *(_QWORD *)(v11 + 416);
        v10 = &unk_14D81;
        goto LABEL_9;
      }
    }
    else if ( v5 <= 5 )
    {
      goto LABEL_7;
    }
  }
  __break(0x5512u);
  return select_mode(a1, a2);
}
