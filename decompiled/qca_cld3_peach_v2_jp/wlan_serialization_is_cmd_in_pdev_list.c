bool __fastcall wlan_serialization_is_cmd_in_pdev_list(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w22
  _QWORD *v13; // x1
  const char *v14; // x21
  _BOOL8 result; // x0
  _QWORD *v16; // [xsp+0h] [xbp-10h] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a2 + 16);
  v16 = nullptr;
  if ( !v10 )
  {
LABEL_14:
    result = 0;
    goto LABEL_15;
  }
  if ( !a2 )
  {
    v14 = "%s: input parameters are invalid";
LABEL_13:
    qdf_trace_msg(0x4Cu, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_serialization_get_cmd_from_queue", v16, v17);
    goto LABEL_14;
  }
  v13 = nullptr;
  v14 = "%s: can't get next node from queue";
  while ( 1 )
  {
    if ( v13 )
    {
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)a2, v13, &v16) )
        goto LABEL_13;
    }
    else if ( (unsigned int)qdf_list_peek_front((_QWORD *)a2, &v16) )
    {
      goto LABEL_13;
    }
    v13 = v16;
    if ( *(_QWORD *)(v16[8] + 152LL) == a1 )
      break;
    if ( !--v10 )
    {
      v13 = nullptr;
      break;
    }
  }
  result = v13 != nullptr;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
