__int64 __fastcall gpio_keys_resume(__int64 a1)
{
  unsigned int *v1; // x21
  __int64 v2; // x22
  __int64 v3; // x22
  unsigned int *v4; // x23
  int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x0
  int v9; // w0
  unsigned int **v10; // x23
  unsigned int *v11; // x8
  __int64 (__fastcall *v12)(_QWORD); // x9
  __int64 v13; // x0
  unsigned int v14; // w0
  unsigned int v15; // w19
  __int64 v17; // x19
  unsigned int *v18; // x19
  __int64 v19; // x24
  unsigned int **v20; // x20
  __int64 v21; // x22
  unsigned int **v22; // x20

  v1 = *(unsigned int **)(a1 + 152);
  v2 = *((_QWORD *)v1 + 1);
  if ( (*(_WORD *)(a1 + 268) & 1) == 0 || !*(_QWORD *)(a1 + 328) )
  {
    mutex_lock(v2 + 504);
    if ( *(_DWORD *)(v2 + 552) )
    {
      v10 = *(unsigned int ***)(v2 + 712);
      v11 = *v10;
      v12 = *((__int64 (__fastcall **)(_QWORD))*v10 + 3);
      if ( v12 )
      {
        v13 = *(_QWORD *)(v2 + 656);
        if ( *((_DWORD *)v12 - 1) != 711998475 )
          __break(0x8229u);
        v14 = v12(v13);
        if ( v14 )
        {
          v15 = v14;
          mutex_unlock(v2 + 504);
          return v15;
        }
        v11 = *v10;
      }
      v18 = v10[1];
      if ( (int)v11[2] >= 1 )
      {
        v19 = 0;
        v20 = v10 + 9;
        do
        {
          if ( v20[2] )
          {
            gpio_keys_gpio_report_event(v20);
            v11 = *v10;
          }
          ++v19;
          v20 += 34;
        }
        while ( v19 < (int)v11[2] );
      }
      input_event(v18, 0, 0, 0);
    }
    mutex_unlock(v2 + 504);
    v6 = *(_QWORD *)v1;
    LODWORD(v7) = *(_DWORD *)(*(_QWORD *)v1 + 8LL);
    goto LABEL_27;
  }
  if ( *(int *)(*(_QWORD *)v1 + 8LL) > 0 )
  {
    v3 = 0;
    v4 = v1 + 65;
    do
    {
      v8 = *v4;
      *((_BYTE *)v4 + 78) = 0;
      if ( (*(_BYTE *)(*(_QWORD *)(irq_get_irq_data(v8) + 16) + 1LL) & 0x40) != 0 )
      {
        if ( v4[17] )
        {
          v9 = irq_set_irq_type(*v4);
          if ( v9 )
            dev_warn(
              *(_QWORD *)(*(_QWORD *)(v4 - 45) + 656LL),
              "failed to restore interrupt trigger for IRQ %d: %d\n",
              *v4,
              v9);
        }
        v5 = irq_set_irq_wake(*v4, 0);
        if ( v5 )
          dev_warn(*(_QWORD *)(*(_QWORD *)(v4 - 45) + 656LL), "failed to disable IRQ %d as wake source: %d\n", *v4, v5);
      }
      v6 = *(_QWORD *)v1;
      ++v3;
      v4 += 68;
      v7 = *(int *)(*(_QWORD *)v1 + 8LL);
    }
    while ( v3 < v7 );
LABEL_27:
    v17 = *((_QWORD *)v1 + 1);
    if ( (int)v7 >= 1 )
    {
      v21 = 0;
      v22 = (unsigned int **)(v1 + 18);
      do
      {
        if ( v22[2] )
        {
          gpio_keys_gpio_report_event(v22);
          v6 = *(_QWORD *)v1;
        }
        ++v21;
        v22 += 34;
      }
      while ( v21 < *(int *)(v6 + 8) );
    }
    goto LABEL_32;
  }
  v17 = *((_QWORD *)v1 + 1);
LABEL_32:
  input_event(v17, 0, 0, 0);
  return 0;
}
