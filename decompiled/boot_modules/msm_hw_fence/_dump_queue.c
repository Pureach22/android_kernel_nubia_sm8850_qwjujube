__int64 __fastcall dump_queue(__int64 a1, __int64 a2, unsigned int *a3, unsigned int a4)
{
  __int64 v4; // x30
  unsigned int *v6; // x8
  signed int v7; // w9
  unsigned int *v8; // x19
  int v9; // w21
  __int64 result; // x0
  unsigned int v11; // w9
  unsigned int v12; // w22
  __int64 v13; // x25
  int v14; // w8
  __int64 v15; // x27
  __int64 v16; // x28
  __int64 queue_type; // x0
  unsigned int v18; // w22
  __int64 v19; // x21
  __int64 v20; // x5
  __int64 v21; // [xsp+30h] [xbp-20h] BYREF
  __int64 v22; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v23[2]; // [xsp+40h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = &a3[12 * a4];
  v7 = a3[34];
  v22 = 0;
  v23[0] = 0;
  v21 = 0;
  v8 = v6 + 10;
  if ( v7 >= (int)a4 && v6 != (unsigned int *)-40LL && *((_QWORD *)v6 + 7) && *(_QWORD *)v8 )
  {
    __dsb(0xFu);
    v9 = a2;
    result = dump_queue_header(a1, a2, v8, *a3, a4, v23, &v22, &v21);
    v11 = v8[2];
    if ( v11 >= 0x40 )
    {
      v12 = 0;
      v13 = 0;
      v14 = msm_hw_fence_debug_level;
      v15 = v11 & 0xFFFFFFC0;
      do
      {
        if ( (v14 & v9) != 0 && (v14 & 0x10000) != 0 )
        {
          v16 = *(_QWORD *)v8 + v13;
          queue_type = get_queue_type(a4);
          result = printk(&unk_20E93, "_dump_queue_payload", 820, queue_type, v12, *(_QWORD *)(v16 + 24));
          v14 = msm_hw_fence_debug_level;
        }
        v13 += 64;
        ++v12;
      }
      while ( v15 != v13 );
    }
  }
  else
  {
    v18 = *a3;
    v19 = v4;
    v20 = get_queue_type(a4);
    result = printk(&unk_20E2F, "_dump_queue", 838, v19, v18, v20);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
