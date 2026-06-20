__int64 __fastcall dump_event(__int64 result, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x30
  int v8; // w22
  __int64 v9; // x5
  int v10; // w24
  int *v11; // x25
  __int64 v12; // x26
  int v13; // t1

  if ( !a2 || !a3 )
    return printk(&unk_2ABCD, "_dump_event", 649, v4, a2, a3);
  *(_DWORD *)(a3 + 104) = 0;
  v8 = result;
  *(_QWORD *)(a3 + 88) = 0;
  *(_QWORD *)(a3 + 96) = 0;
  *(_QWORD *)(a3 + 72) = 0;
  *(_QWORD *)(a3 + 80) = 0;
  *(_QWORD *)(a3 + 56) = 0;
  *(_QWORD *)(a3 + 64) = 0;
  *(_QWORD *)(a3 + 40) = 0;
  *(_QWORD *)(a3 + 48) = 0;
  *(_QWORD *)(a3 + 24) = 0;
  *(_QWORD *)(a3 + 32) = 0;
  *(_QWORD *)(a3 + 8) = 0;
  *(_QWORD *)(a3 + 16) = 0;
  *(_QWORD *)a3 = 0;
  v9 = *(unsigned int *)(a2 + 12);
  if ( (unsigned int)v9 >= 0xD )
  {
    printk(&unk_29B95, "_dump_event", 656, v4, a4, v9);
    LODWORD(v9) = 12;
  }
  else if ( !(_DWORD)v9 )
  {
    goto LABEL_7;
  }
  v10 = 0;
  v11 = (int *)(a2 + 16);
  v12 = (unsigned int)v9;
  do
  {
    v13 = *v11++;
    result = scnprintf(a3 + v10, 108 - v10, "%x|", v13);
    --v12;
    v10 += result;
  }
  while ( v12 );
LABEL_7:
  if ( (msm_hw_fence_debug_level & v8) != 0 && (msm_hw_fence_debug_level & 0x10000) != 0 )
    return printk(&unk_216A2, "_dump_event", 666, a4, *(unsigned int *)(a2 + 8), *(_QWORD *)a2);
  return result;
}
