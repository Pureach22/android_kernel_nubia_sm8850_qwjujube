__int64 __fastcall vi530x_irq_handler(int a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 (__fastcall *v3)(_QWORD); // x8
  int v4; // w0
  __int64 v5; // x19
  unsigned int (__fastcall *v6)(_QWORD); // x8

  if ( a2 && *(_BYTE *)(a2 + 233) && *(_DWORD *)(a2 + 220) == a1 )
  {
    if ( xtalk_mark != 1 )
      goto LABEL_8;
    v2 = a2;
    v3 = *(__int64 (__fastcall **)(_QWORD))(vi530x_func_tbl + 88);
    if ( *((_DWORD *)v3 - 1) != 1318018478 )
      __break(0x8228u);
    v4 = v3(a2);
    a2 = v2;
    if ( v4 )
    {
      printk(&unk_3CFE2F);
      a2 = v2;
      if ( (xtalk_mark & 1) != 0 )
        return 1;
    }
    else
    {
LABEL_8:
      if ( (xtalk_mark & 1) != 0 )
        return 1;
    }
    if ( (offset_mark & 1) == 0 && !dword_3C84D0 )
    {
      v5 = a2;
      v6 = *(unsigned int (__fastcall **)(_QWORD))(vi530x_func_tbl + 48);
      if ( *((_DWORD *)v6 - 1) != 1318018478 )
        __break(0x8228u);
      if ( v6(a2) )
      {
        printk(&unk_3CFE2F);
      }
      else
      {
        input_event(*(_QWORD *)(v5 + 104), 3, 16, (unsigned int)*(__int16 *)(v5 + 16));
        input_event(*(_QWORD *)(v5 + 104), 3, 17, *(unsigned __int8 *)(v5 + 18));
        input_event(*(_QWORD *)(v5 + 104), 3, 18, *(unsigned int *)(v5 + 20));
        input_event(*(_QWORD *)(v5 + 104), 3, 19, *(unsigned int *)(v5 + 24));
        input_event(*(_QWORD *)(v5 + 104), 3, 20, *(unsigned int *)(v5 + 28));
        input_event(*(_QWORD *)(v5 + 104), 0, 0, 0);
      }
    }
  }
  return 1;
}
