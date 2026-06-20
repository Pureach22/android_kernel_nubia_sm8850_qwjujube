__int64 __fastcall dsi_display_cb_error_handler(__int64 a1, unsigned int a2)
{
  __int64 v3; // x1
  __int64 v4; // x2

  if ( !a1 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 1376);
  if ( !v3 )
    return 4294967274LL;
  switch ( a2 )
  {
    case 1u:
      v4 = a1 + 1416;
      break;
    case 3u:
      v4 = a1 + 1448;
      break;
    case 2u:
      v4 = a1 + 1384;
      break;
    default:
      printk(&unk_24453E, a2);
      return 0;
  }
  queue_work_on(32, v3, v4);
  return 0;
}
