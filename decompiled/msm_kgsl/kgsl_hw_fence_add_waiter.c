__int64 __fastcall kgsl_hw_fence_add_waiter(_QWORD *a1, __int64 a2, unsigned int *a3)
{
  unsigned int v6; // w0
  unsigned int v7; // w19
  unsigned int v8; // w0
  unsigned int v10; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v11[2]; // [xsp+8h] [xbp-38h] BYREF
  int v12; // [xsp+18h] [xbp-28h]
  int v13; // [xsp+1Ch] [xbp-24h]
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 1;
  v10 = 0;
  v15 = 0;
  v11[1] = &v10;
  v13 = 0;
  v14 = a2;
  v12 = 8;
  v16 = 0;
  v6 = synx_import(kgsl_synx, v11);
  if ( v6 )
  {
    v7 = v6;
    if ( (unsigned int)__ratelimit(&kgsl_hw_fence_add_waiter__rs, "kgsl_hw_fence_add_waiter") )
      dev_err(
        *a1,
        "Failed to add GMU as waiter ret:%d fence ctx:%llu ts:%llu\n",
        v7,
        *(_QWORD *)(a2 + 32),
        *(_QWORD *)(a2 + 40));
  }
  else
  {
    v8 = synx_release(kgsl_synx, v10);
    if ( v8 )
    {
      v7 = v8;
      if ( (unsigned int)__ratelimit(&kgsl_hw_fence_add_waiter__rs_3, "kgsl_hw_fence_add_waiter") )
        dev_err(
          *a1,
          "Failed to release wait fences ret:%d fence ctx:%llu ts:%llu\n",
          v7,
          *(_QWORD *)(a2 + 32),
          *(_QWORD *)(a2 + 40));
    }
    else
    {
      v7 = 0;
      if ( a3 )
        *a3 = v10;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
