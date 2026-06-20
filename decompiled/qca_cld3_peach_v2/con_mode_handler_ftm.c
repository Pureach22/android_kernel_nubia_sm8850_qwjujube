__int64 con_mode_handler_ftm()
{
  double v0; // d0
  unsigned int v1; // w0
  unsigned int v2; // w19
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  void *v22; // x0

  v0 = param_set_int();
  v2 = v1;
  if ( (cds_get_driver_state(v0, v3, v4, v5, v6, v7, v8, v9) & 1) != 0
    || (cds_get_driver_state(v13, v14, v15, v16, v17, v18, v19, v20) & 6) != 0 )
  {
    v22 = &unk_A707B9;
LABEL_8:
    printk(v22, v10, v11, v12);
    return (unsigned int)-524;
  }
  if ( con_mode_ftm != 5 )
  {
    v22 = &unk_A196F3;
    goto LABEL_8;
  }
  curr_con_mode = 5;
  con_mode = 5;
  return v2;
}
