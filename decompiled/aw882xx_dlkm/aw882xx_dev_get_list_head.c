__int64 __fastcall aw882xx_dev_get_list_head(_QWORD *a1)
{
  if ( g_dev_list == (_UNKNOWN *)&g_dev_list )
    return 4294967274LL;
  *a1 = &g_dev_list;
  return 0;
}
