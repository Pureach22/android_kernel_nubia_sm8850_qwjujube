__int64 __fastcall tpd_set_display_rotation(__int64 a1, int a2, __int64 a3)
{
  _QWORD *v4; // x20
  __int64 v7; // x9
  unsigned int v8; // w21
  __int64 v9; // x2
  __int64 v10; // x2

  v4 = *(_QWORD **)(a1 + 3072);
  printk(&unk_34878, "tpd_set_display_rotation", a3);
  if ( !v4 )
    return 4294967274LL;
  v7 = v4[78];
  if ( *(_DWORD *)(v7 + 184) && (*(_BYTE *)(v7 + 188) & 1) != 0 )
    v8 = 0;
  else
    v8 = *(_DWORD *)(*v4 + 524LL);
  *(_DWORD *)(a1 + 16) = a2;
  *((_DWORD *)v4 + 386) = a2;
  printk(&unk_37B3D, "tpd_set_display_rotation", *(unsigned int *)(a1 + 16));
  if ( *((_DWORD *)v4 + 351) != 1 )
  {
    printk(&unk_3C397, "tpd_set_display_rotation", 0);
    msleep(200);
    if ( *((_DWORD *)v4 + 351) != 1 )
    {
      printk(&unk_3C397, "tpd_set_display_rotation", 1);
      msleep(200);
      if ( *((_DWORD *)v4 + 351) != 1 )
      {
        printk(&unk_3C397, "tpd_set_display_rotation", 2);
        msleep(200);
        if ( *((_DWORD *)v4 + 351) != 1 )
        {
          printk(&unk_3C397, "tpd_set_display_rotation", 3);
          msleep(200);
          if ( *((_DWORD *)v4 + 351) != 1 )
          {
            printk(&unk_3C397, "tpd_set_display_rotation", 4);
            msleep(200);
            printk(&unk_38BA1, "tpd_set_display_rotation", v10);
            return 4294967274LL;
          }
        }
      }
    }
  }
  if ( (syna_dev_set_display_rotation(v4, *(_DWORD *)(a1 + 16), v8) & 0x80000000) != 0 )
    printk(&unk_36936, "tpd_set_display_rotation", v9);
  return *(unsigned int *)(a1 + 16);
}
