__int64 __fastcall btfmcodec_wq_hwep_shutdown(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x24
  _QWORD *v4; // x25
  int v5; // w0
  char v6; // w8

  v1 = *(_QWORD *)(a1 + 352);
  printk(&unk_C790, "btfmcodec_wq_hwep_shutdown");
  v3 = *(_QWORD **)(v1 + 992);
  if ( v3 != (_QWORD *)(v1 + 992) )
  {
    while ( 1 )
    {
      v4 = (_QWORD *)*v3;
      printk(&unk_DBC0, "btfmcodec_wq_hwep_shutdown");
      v5 = btfmcodec_hwep_shutdown(v1, *((unsigned __int8 *)v3 - 24), 1);
      *((_BYTE *)v3 - 7) = 0;
      if ( v5 < 0 )
        break;
      v3 = v4;
      if ( v4 == (_QWORD *)(v1 + 992) )
      {
        v6 = 1;
        goto LABEL_7;
      }
    }
    printk(&unk_D2FE, "btfmcodec_wq_hwep_shutdown");
  }
  v6 = 2;
LABEL_7:
  *(_BYTE *)(a1 + 348) = v6;
  return _wake_up(a1 + 248, 1, 1, 0);
}
