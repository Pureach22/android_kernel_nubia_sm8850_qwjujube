__int64 __fastcall check_detached_context_hardware_fences_0(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x21
  __int64 v6; // x9
  _QWORD *v7; // x23
  unsigned int v8; // w3
  unsigned int v9; // w10
  unsigned int v10; // w10
  bool v11; // cf
  unsigned int v12; // w10
  unsigned int v13; // w21
  _QWORD *v14; // x21
  __int64 v15; // x21
  _QWORD *v16; // x23
  _QWORD *v17; // t1
  unsigned int v18; // w0

  v2 = *(_QWORD **)(a2 + 2072);
  v3 = (_QWORD *)(a2 + 2072);
  if ( v2 == (_QWORD *)(a2 + 2072) )
  {
LABEL_11:
    v14 = *(_QWORD **)(a2 + 2056);
    if ( v14 == (_QWORD *)(a2 + 2056) )
      return 0;
    while ( 1 )
    {
      v17 = (_QWORD *)*v14;
      v15 = (__int64)(v14 - 8);
      v16 = v17;
      v18 = gen8_send_hw_fence_hfi_wait_ack(a1, v15, 1);
      if ( v18 )
        break;
      adreno_hwsched_remove_hw_fence_entry(a1, v15);
      v14 = v16;
      if ( v16 == (_QWORD *)(a2 + 2056) )
        return 0;
    }
    v13 = v18;
  }
  else
  {
    while ( 1 )
    {
      v6 = *(_QWORD *)(a2 + 1648);
      v7 = (_QWORD *)*v2;
      v8 = *((_DWORD *)v2 - 10);
      v9 = *(_DWORD *)(v6 + 12);
      if ( v8 != v9 )
      {
        if ( v8 > v9 && ((v8 - v9) & 0x80000000) == 0 )
          break;
        v10 = v9 ^ 0x80000000;
        v11 = (v8 ^ 0x80000000) >= v10;
        v12 = (v8 ^ 0x80000000) - v10;
        if ( v12 != 0 && v11 && v12 < 0x80000001 )
          break;
      }
      adreno_hwsched_remove_hw_fence_entry(a1, v2 - 8);
      v2 = v7;
      if ( v7 == v3 )
        goto LABEL_11;
    }
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "detached ctx:%d has unsignaled fence ts:%d retired:%d\n",
      *(_DWORD *)(a2 + 4),
      v8,
      *(_DWORD *)(v6 + 12));
    v13 = -22;
  }
  move_detached_context_hardware_fences_0(a1, a2);
  gmu_core_fault_snapshot(a1, 14);
  gen8_hwsched_fault(a1, 32);
  return v13;
}
