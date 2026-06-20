_BYTE *__fastcall dsi_parser_get_head_node(_QWORD *a1, const void *a2, int a3)
{
  __int64 v3; // x20
  __int64 v5; // x22
  _BYTE *result; // x0
  _BYTE *v8; // x22
  __int64 nodes; // x0
  __int64 v10; // x1
  __int64 v11; // x0

  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a2 || (LODWORD(v3) = a3) == 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid input\n");
    goto LABEL_9;
  }
  v5 = (unsigned int)(a3 + 1);
  result = (_BYTE *)devm_kmalloc(a1[3], v5, 3520);
  a1[4] = result;
  if ( !result )
  {
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v3 = (unsigned int)v3;
  if ( (_DWORD)v3 != -1 )
  {
    v8 = result;
    memcpy(result, a2, (unsigned int)v3);
    v8[(unsigned int)v3] = 0;
    strreplace(v8, 10, 32);
    strreplace(v8, 9, 42);
    nodes = dsi_parser_find_nodes(a1[3]);
    a1[1] = nodes;
    if ( nodes )
    {
      dsi_parser_count_properties(nodes, v10);
      ((void (__fastcall *)(_QWORD, _QWORD))dsi_parser_get_properties)(a1[3], a1[1]);
      result = (_BYTE *)a1[1];
      a1[2] = result;
      goto LABEL_10;
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: could not get head node\n");
    devm_kfree(a1[3]);
LABEL_9:
    result = nullptr;
    goto LABEL_10;
  }
  v11 = _fortify_panic(17, v5, v3);
  return (_BYTE *)dsi_parser_find_nodes(v11);
}
