__int64 __fastcall action_oui_extension_store(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x10

  qdf_mutex_acquire(a2 + 32);
  if ( *(_DWORD *)a2 >= 0x13u )
    v6 = 100;
  else
    v6 = 10;
  if ( *(_DWORD *)(a2 + 24) == v6 )
  {
    qdf_mutex_release(a2 + 32);
    qdf_trace_msg(
      0x63u,
      2u,
      "%s: Reached maximum OUI extensions",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "action_oui_extension_store");
    return 16;
  }
  else
  {
    v16 = _qdf_mem_malloc(0x58u, "action_oui_extension_store", 489);
    if ( v16 )
    {
      *(_QWORD *)(v16 + 16) = *(_QWORD *)a3;
      v17 = *(_QWORD *)(a3 + 32);
      v18 = *(_QWORD *)(a3 + 8);
      v19 = *(_QWORD *)(a3 + 16);
      *(_QWORD *)(v16 + 40) = *(_QWORD *)(a3 + 24);
      *(_QWORD *)(v16 + 48) = v17;
      *(_QWORD *)(v16 + 24) = v18;
      *(_QWORD *)(v16 + 32) = v19;
      v21 = *(_QWORD *)(a3 + 48);
      v20 = *(_QWORD *)(a3 + 56);
      v22 = *(_QWORD *)(a3 + 40);
      *(_DWORD *)(v16 + 80) = *(_DWORD *)(a3 + 64);
      *(_QWORD *)(v16 + 64) = v21;
      *(_QWORD *)(v16 + 72) = v20;
      *(_QWORD *)(v16 + 56) = v22;
      qdf_list_insert_back((_QWORD *)(a2 + 8), (_QWORD *)v16);
      ++*(_DWORD *)(a1 + 23532);
      qdf_mutex_release(a2 + 32);
      return 0;
    }
    else
    {
      qdf_mutex_release(a2 + 32);
      return 2;
    }
  }
}
