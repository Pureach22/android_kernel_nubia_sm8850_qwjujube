__int64 __fastcall qcom_alloc_io_pgtable_ops(unsigned int a1, _QWORD *a2, __int64 a3)
{
  __int64 result; // x0
  int v4; // w19
  __int64 (__fastcall **v5)(); // x8
  __int64 (__fastcall *v6)(); // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x8
  __int64 v17; // x10
  __int64 v18; // x11

  if ( a1 <= 9 )
    return alloc_io_pgtable_ops();
  if ( a1 == -1 )
  {
    v4 = -1;
    v5 = io_pgtable_av8l_fast_init_fns;
  }
  else
  {
    if ( a1 != -2 )
    {
      printk(&unk_11C2A);
      return 0;
    }
    v4 = -2;
    v5 = qcom_io_pgtable_arm_64_lpae_s1_init_fns;
  }
  v6 = *v5;
  if ( *((_DWORD *)v6 - 1) != -926497941 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD *, __int64))v6)(a2, a3);
  if ( result )
  {
    *(_DWORD *)result = v4;
    *(_QWORD *)(result + 8) = a3;
    v9 = a2[1];
    *(_QWORD *)(result + 16) = *a2;
    *(_QWORD *)(result + 24) = v9;
    v10 = a2[5];
    v11 = a2[2];
    v12 = a2[3];
    *(_QWORD *)(result + 48) = a2[4];
    *(_QWORD *)(result + 56) = v10;
    *(_QWORD *)(result + 32) = v11;
    *(_QWORD *)(result + 40) = v12;
    v13 = a2[9];
    v14 = a2[6];
    v15 = a2[7];
    *(_QWORD *)(result + 80) = a2[8];
    *(_QWORD *)(result + 88) = v13;
    *(_QWORD *)(result + 64) = v14;
    *(_QWORD *)(result + 72) = v15;
    v16 = a2[13];
    v17 = a2[10];
    v18 = a2[11];
    *(_QWORD *)(result + 112) = a2[12];
    *(_QWORD *)(result + 120) = v16;
    *(_QWORD *)(result + 96) = v17;
    *(_QWORD *)(result + 104) = v18;
    result += 128;
  }
  return result;
}
