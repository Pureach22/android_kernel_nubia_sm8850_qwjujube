__int64 __fastcall icnss_get_soc_info(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  size_t v4; // x0
  unsigned __int64 v5; // x2
  size_t v6; // x0
  unsigned __int64 v7; // x2
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x11

  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 )
  {
    printk("%sicnss2: Platform driver not initialized\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Platform driver not initialized\n", (const char *)&unk_12DBF3);
    return 4294967274LL;
  }
  *(_QWORD *)a2 = *(_QWORD *)(v2 + 536);
  *(_QWORD *)(a2 + 8) = *(_QWORD *)(v2 + 528);
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(v2 + 1840);
  *(_DWORD *)(a2 + 20) = *(_DWORD *)(v2 + 1844);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(v2 + 1848);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(v2 + 1852);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(v2 + 1856);
  *(_BYTE *)(v2 + 1892) = 0;
  v4 = strnlen((const char *)(v2 + 1860), 0x21u);
  if ( v4 >= 0x22 )
  {
    _fortify_panic(2, 33, v4 + 1);
LABEL_16:
    v6 = _fortify_panic(7, 33, v5);
    goto LABEL_17;
  }
  if ( v4 == 33 )
    v5 = 33;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x22 )
    goto LABEL_16;
  sized_strscpy(a2 + 36, v2 + 1860);
  v6 = strnlen((const char *)(v2 + 1896), 0x81u);
  if ( v6 >= 0x82 )
  {
LABEL_17:
    _fortify_panic(2, 129, v6 + 1);
LABEL_18:
    _fortify_panic(7, 129, v7);
    return icnss_get_mhi_state();
  }
  if ( v6 == 129 )
    v7 = 129;
  else
    v7 = v6 + 1;
  if ( v7 >= 0x82 )
    goto LABEL_18;
  sized_strscpy(a2 + 69, v2 + 1896);
  result = 0;
  *(_DWORD *)(a2 + 200) = *(_DWORD *)(v2 + 6100);
  *(_DWORD *)(a2 + 204) = *(_DWORD *)(v2 + 6104);
  *(_DWORD *)(a2 + 208) = *(_DWORD *)(v2 + 6108);
  v9 = *(_QWORD *)(v2 + 2136);
  v10 = *(_QWORD *)(v2 + 2112);
  v11 = *(_QWORD *)(v2 + 2120);
  *(_QWORD *)(a2 + 264) = *(_QWORD *)(v2 + 2128);
  *(_QWORD *)(a2 + 272) = v9;
  *(_QWORD *)(a2 + 248) = v10;
  *(_QWORD *)(a2 + 256) = v11;
  v12 = *(_QWORD *)(v2 + 2104);
  v13 = *(_QWORD *)(v2 + 2080);
  v14 = *(_QWORD *)(v2 + 2088);
  *(_QWORD *)(a2 + 232) = *(_QWORD *)(v2 + 2096);
  *(_QWORD *)(a2 + 240) = v12;
  *(_QWORD *)(a2 + 216) = v13;
  *(_QWORD *)(a2 + 224) = v14;
  return result;
}
