__int64 __fastcall dump_fence_helper(__int64 result, unsigned int *a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  __int64 v5; // x30
  int v8; // w23
  __int64 v10; // x5
  unsigned int v11; // w25
  __int64 *v12; // x26
  __int64 v13; // x27
  __int64 v14; // t1
  __int64 v16; // [xsp+68h] [xbp-28h] BYREF
  __int64 v17; // [xsp+70h] [xbp-20h]
  _BYTE v18[11]; // [xsp+78h] [xbp-18h] BYREF
  __int64 v19; // [xsp+88h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  memset(v18, 0, sizeof(v18));
  v16 = 0;
  if ( a2 && a3 )
  {
    *(_WORD *)(a3 + 40) = 0;
    v8 = result;
    *(_QWORD *)(a3 + 24) = 0;
    *(_QWORD *)(a3 + 32) = 0;
    *(_QWORD *)(a3 + 8) = 0;
    *(_QWORD *)(a3 + 16) = 0;
    *(_QWORD *)a3 = 0;
    v10 = a2[20];
    if ( (_DWORD)v10 )
    {
      if ( (unsigned int)v10 >= 4 )
      {
        printk(&unk_2164A, "_dump_fence_helper", 83, v5, a4, v10);
        LODWORD(v10) = 3;
      }
      v11 = 0;
      v12 = (__int64 *)(a2 + 14);
      v13 = (unsigned int)v10;
      v17 = 0;
      memset(v18, 0, sizeof(v18));
      v16 = 0;
      do
      {
        if ( v11 >= 0x1C )
          __break(0x5512u);
        v14 = *v12++;
        --v13;
        v11 += scnprintf((char *)&v16 + v11, 27 - v11, "%llu,", v14);
      }
      while ( v13 );
      result = scnprintf(a3, 42, " p:[%s]", (const char *)&v16);
    }
    if ( (msm_hw_fence_debug_level & v8) != 0 && (msm_hw_fence_debug_level & 0x10000) != 0 )
      result = printk(&unk_2080F, "_dump_fence_helper", 101, a5, a4, *a2);
  }
  else
  {
    result = printk(&unk_27694, "_dump_fence_helper", 75, v5, a2, a3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
