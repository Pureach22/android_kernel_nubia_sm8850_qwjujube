__int64 __fastcall wmi_fill_data_synch_frame_event(__int64 a1, __int64 a2)
{
  int v4; // w8
  __int64 v5; // x8
  unsigned __int16 v6; // w8
  int v7; // w9
  unsigned __int16 v8; // w8
  int v9; // w9
  unsigned __int16 v10; // w8
  int v11; // w9
  __int64 result; // x0

  *(_WORD *)a2 = 2504;
  v4 = *(_DWORD *)(a1 + 872);
  *(_WORD *)(a2 + 2) = v4;
  qdf_mem_copy((void *)(a2 + 2504), *(const void **)(a1 + 880), (unsigned __int16)v4);
  _qdf_mem_free(*(_QWORD *)(a1 + 880));
  v5 = *(_QWORD *)(a1 + 896);
  *(_QWORD *)(a1 + 880) = 0;
  if ( v5 )
  {
    v6 = *(_WORD *)(a2 + 2) + 2504;
    *(_WORD *)(a2 + 2492) = v6;
    v7 = *(_DWORD *)(a1 + 892);
    *(_WORD *)(a2 + 2494) = v7;
    *(_BYTE *)(a2 + 2496) = *(_BYTE *)(a1 + 904);
    qdf_mem_copy((void *)(a2 + v6), *(const void **)(a1 + 896), (unsigned __int16)v7);
    _qdf_mem_free(*(_QWORD *)(a1 + 896));
    *(_QWORD *)(a1 + 896) = 0;
  }
  v8 = *(_WORD *)(a2 + 2) + *(_WORD *)(a2 + 2494) + 2504;
  *(_WORD *)(a2 + 4) = v8;
  v9 = *(_DWORD *)(a1 + 920);
  *(_WORD *)(a2 + 6) = v9;
  qdf_mem_copy((void *)(a2 + v8), *(const void **)(a1 + 928), (unsigned __int16)v9);
  _qdf_mem_free(*(_QWORD *)(a1 + 928));
  *(_QWORD *)(a1 + 928) = 0;
  v10 = *(_WORD *)(a2 + 2) + *(_WORD *)(a2 + 2494) + *(_WORD *)(a2 + 6) + 2504;
  *(_WORD *)(a2 + 8) = v10;
  v11 = *(_DWORD *)(a1 + 908);
  *(_WORD *)(a2 + 10) = v11;
  qdf_mem_copy((void *)(a2 + v10), *(const void **)(a1 + 912), (unsigned __int16)v11);
  result = _qdf_mem_free(*(_QWORD *)(a1 + 912));
  *(_QWORD *)(a1 + 912) = 0;
  return result;
}
