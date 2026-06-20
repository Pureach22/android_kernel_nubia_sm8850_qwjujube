__int64 __fastcall wmi_unified_get_pdev_handle(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x22
  __int16 v6; // w8
  __int64 v8; // x23
  __int64 v9; // x1
  __int64 v10; // x20
  __int64 v11; // x9
  __int64 v12; // x9

  if ( a2 > 2 )
    return 0;
  v3 = a1;
  v4 = a2;
  v5 = a1 + 5184;
  result = *(_QWORD *)(a1 + 5184 + 8LL * a2);
  if ( result )
  {
LABEL_4:
    *(_DWORD *)(result + 24) = 0;
    *(_BYTE *)(result + 737) = 0;
    *(_DWORD *)(result + 28) = *(_DWORD *)(v3 + 4 * v4 + 5208);
    *(_QWORD *)(result + 64) = *(_QWORD *)(v3 + 32);
    v6 = *(_WORD *)(v3 + 2 * v4 + 5220);
    *(_BYTE *)(result + 720) = 0;
    *(_WORD *)(result + 32) = v6;
    return result;
  }
  v8 = v3;
  result = _qdf_mem_malloc(0x380u, "wmi_unified_get_pdev_handle", 3250);
  if ( result )
  {
    v10 = result;
    if ( (unsigned int)wmi_initialize_worker_context(result, v9) )
    {
      _qdf_mem_free(v10);
      return 0;
    }
    v11 = *(_QWORD *)(v8 + 8);
    *(_QWORD *)(v10 + 40) = v8 + 40;
    *(_QWORD *)(v10 + 48) = v8 + 1064;
    *(_QWORD *)v10 = v11;
    *(_QWORD *)(v10 + 56) = v8 + 3116;
    v12 = *(_QWORD *)(v8 + 5232);
    *(_QWORD *)(v10 + 760) = v8;
    *(_QWORD *)(v10 + 744) = v8 + 5252;
    *(_QWORD *)(v10 + 728) = v12;
    *(_QWORD *)(v10 + 752) = v8 + 6368;
    *(_QWORD *)(v10 + 856) = v8 + 7700;
    *(_QWORD *)(v10 + 864) = v8 + 7712;
    *(_QWORD *)(v10 + 872) = v8 + 7724;
    *(_QWORD *)(v10 + 880) = v8 + 7736;
    wmi_interface_logging_init(v10, a2);
    *(_DWORD *)(v10 + 696) = 0;
    result = v10;
    v3 = v8;
    *(_DWORD *)(v10 + 716) = 0;
    *(_DWORD *)(v10 + 724) = *(_DWORD *)(v8 + 20);
    *(_WORD *)(v10 + 768) = *(_WORD *)(v8 + 7692);
    *(_QWORD *)(v5 + 8 * v4) = v10;
    goto LABEL_4;
  }
  return result;
}
