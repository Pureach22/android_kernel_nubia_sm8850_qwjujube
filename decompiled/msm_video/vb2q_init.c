__int64 __fastcall vb2q_init(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x9
  __int16 v6; // w8
  __int64 v7; // x9
  __int64 result; // x0
  __int64 v9; // x2
  unsigned int v10; // w20

  v3 = *(_QWORD *)(a1 + 320);
  *(_DWORD *)a2 = a3;
  *(_DWORD *)(a2 + 4) = 17;
  *(_DWORD *)(a2 + 88) = 0x4000;
  *(_QWORD *)(a2 + 48) = *(_QWORD *)(v3 + 6520);
  v6 = *(_WORD *)(a2 + 320);
  v7 = *(_QWORD *)(v3 + 6528);
  *(_QWORD *)(a2 + 72) = a1;
  *(_QWORD *)(a2 + 56) = v7;
  *(_WORD *)(a2 + 320) = v6 | 0x100;
  result = vb2_queue_init(a2);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v9 = a1 + 340;
    v10 = result;
    printk(&unk_94A6E, "err ", v9, "vb2q_init", a3);
    return v10;
  }
  return result;
}
