__int64 __fastcall wlan_ftm_pdev_obj_create_notification(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  _QWORD *v4; // x0
  __int64 v5; // x19
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  unsigned int v16; // w20

  v1 = *(_QWORD *)(a1 + 80);
  if ( !v1 )
    return 5;
  v2 = *(_QWORD *)(v1 + 2800);
  if ( !v2 )
    return 5;
  if ( *(_DWORD *)(v2 + 5768) != 5 )
    return 0;
  v4 = (_QWORD *)_qdf_mem_malloc(0x30u, "wlan_ftm_pdev_obj_create_notification", 79);
  if ( !v4 )
    return 2;
  v5 = (__int64)v4;
  *v4 = a1;
  v6 = _qdf_mem_malloc(0x800u, "ftm_pdev_obj_init", 46);
  *(_QWORD *)(v5 + 8) = v6;
  if ( !v6 )
  {
    LODWORD(result) = 2;
    goto LABEL_13;
  }
  *(_QWORD *)(v5 + 24) = 0;
  *(_DWORD *)(v5 + 40) = 3;
  result = wlan_objmgr_pdev_component_obj_attach(a1, 0x17u, v5, 0, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( (_DWORD)result )
  {
LABEL_13:
    v16 = result;
    _qdf_mem_free(v5);
    return v16;
  }
  return result;
}
