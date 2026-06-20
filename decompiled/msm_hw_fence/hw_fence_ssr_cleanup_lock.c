__int64 __fastcall hw_fence_ssr_cleanup_lock(__int64 a1, __int64 a2, unsigned int a3, unsigned __int64 a4, __int64 a5)
{
  int v8; // w8
  __int64 v9; // x24
  __int64 v10; // x28
  __int64 v11; // x27
  unsigned __int64 v12; // x28
  unsigned int v13; // w27
  unsigned int v14; // w21
  _QWORD *v15; // x1
  __int64 v17; // [xsp+0h] [xbp-10h]

  if ( a1 && a2 && a4 >= 2 )
  {
    if ( a3 )
    {
      v8 = 0;
      do
      {
        v9 = v8;
        if ( a3 <= (unsigned __int64)v8 )
        {
          printk(&unk_23ADB, "_get_hw_fence", 1135, v17, v8);
          v10 = 0;
        }
        else
        {
          v10 = a2 + ((__int64)v8 << 7);
        }
        v11 = v10 + 40;
        if ( *(_QWORD *)(v10 + 40) == a4 )
        {
          if ( (~msm_hw_fence_debug_level & 0x10100) == 0 )
            printk(&unk_2B420, "unlock_in_flight_fence", 2789, a4, a5);
          hw_fence_debug_dump_fence(256, v10, v9, 0);
          v12 = *(_QWORD *)(v10 + 24);
          global_atomic_store(a1, v11, 0);
          v13 = 0;
          v14 = -8;
          do
          {
            if ( ((v12 >> v13) & 1) != 0 )
            {
              v15 = (_QWORD *)(*(_QWORD *)(a1 + 104) + 8LL * v14);
              if ( *v15 == a4 )
              {
                global_atomic_store(a1, v15, 0);
                if ( (~msm_hw_fence_debug_level & 0x10100) == 0 )
                  printk(&unk_2A349, "unlock_in_flight_fence", 2801, v13, a4);
              }
            }
            ++v13;
            v14 += 8;
          }
          while ( v13 <= *(_DWORD *)(a1 + 56) );
        }
        v8 = v9 + 1;
      }
      while ( (_DWORD)v9 + 1 != a3 );
    }
    return 0;
  }
  else
  {
    printk(&unk_22728, "hw_fence_ssr_cleanup_lock", 2815, v17, a1);
    return 4294967274LL;
  }
}
