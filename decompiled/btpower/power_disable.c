__int64 __fastcall power_disable(int a1)
{
  int v2; // w23
  int v3; // w22
  int v4; // w21
  int v5; // w24
  __int64 result; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // w23
  void *v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x19
  __int64 v23; // x24
  __int64 v24; // x19
  int v25; // w0
  int v26; // w24
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x21
  __int64 v34; // x19
  int v35; // w0
  __int64 v36; // x0

  mutex_lock(pwr_data + 224);
  v2 = *(_DWORD *)(pwr_data + 276);
  mutex_unlock(pwr_data + 224);
  mutex_lock(pwr_data + 224);
  v3 = *(_DWORD *)(pwr_data + 280);
  mutex_unlock(pwr_data + 224);
  mutex_lock(pwr_data + 224);
  v4 = *(_DWORD *)(pwr_data + 284);
  mutex_unlock(pwr_data + 224);
  mutex_lock(pwr_data + 224);
  v5 = *(_DWORD *)(pwr_data + 272);
  mutex_unlock(pwr_data + 224);
  result = 0;
  if ( v5 <= 1 )
  {
    if ( v5 == 1 )
    {
      if ( a1 != 2 )
      {
        ((void (__fastcall *)(_QWORD, _QWORD))power_regulators)(0, 0);
LABEL_5:
        LODWORD(v7) = ((__int64 (__fastcall *)(_QWORD))platform_regulators_pwr)(0);
        if ( (_DWORD)v7 )
          printk(&unk_1224B, "power_regulators");
        mutex_lock(pwr_data + 224);
        v8 = pwr_data + 224;
        *(_DWORD *)(pwr_data + 272) = 0;
        mutex_unlock(v8);
        v9 = pwr_data + 224;
        *(_DWORD *)(pwr_data + 288) = 0;
        mutex_lock(v9);
        v10 = pwr_data + 224;
        *(_DWORD *)(pwr_data + 276) = 0;
        mutex_unlock(v10);
        mutex_lock(pwr_data + 224);
        v11 = pwr_data + 224;
        *(_DWORD *)(pwr_data + 280) = 0;
        mutex_unlock(v11);
        goto LABEL_30;
      }
      v14 = &unk_11978;
    }
    else
    {
      if ( v5 )
        return result;
      v14 = &unk_13038;
    }
    goto LABEL_35;
  }
  if ( v5 != 3 )
  {
    if ( v5 != 2 )
      return result;
    if ( a1 != 1 )
    {
      v22 = *(unsigned int *)(pwr_data + 140);
      if ( (_DWORD)v22 )
      {
        printk(&unk_1241F, "uwb_regulators_pwr");
        if ( (int)v22 >= 1 )
        {
          v33 = 0;
          v34 = 48 * v22;
          do
          {
            v35 = vreg_disable(*(_QWORD *)(pwr_data + 64) + v33);
            v33 += 48;
          }
          while ( v34 != v33 );
          if ( v35 )
            printk(&unk_1365B, "power_regulators");
        }
      }
      else
      {
        printk(&unk_12C11, "uwb_regulators_pwr");
      }
      goto LABEL_5;
    }
    v14 = &unk_129CE;
LABEL_35:
    printk(v14, "power_disable");
    return 0;
  }
  if ( a1 != 1 )
  {
    v7 = *(unsigned int *)(pwr_data + 140);
    if ( (_DWORD)v7 )
    {
      printk(&unk_1241F, "uwb_regulators_pwr");
      if ( (int)v7 < 1 )
        goto LABEL_44;
      v23 = 0;
      v24 = 48 * v7;
      do
      {
        v25 = vreg_disable(*(_QWORD *)(pwr_data + 64) + v23);
        v23 += 48;
      }
      while ( v24 != v23 );
      if ( v25 )
      {
        LODWORD(v7) = v25;
        printk(&unk_1365B, "power_regulators");
      }
      else
      {
LABEL_44:
        LODWORD(v7) = 0;
      }
    }
    else
    {
      printk(&unk_12C11, "uwb_regulators_pwr");
    }
    mutex_lock(pwr_data + 224);
    v26 = 1;
    v27 = pwr_data + 224;
    *(_DWORD *)(pwr_data + 272) = 1;
    mutex_unlock(v27);
    if ( v2 != 5 )
    {
      if ( v2 != 3 )
        goto LABEL_49;
      v26 = 0;
    }
    mutex_lock(pwr_data + 224);
    v28 = pwr_data + 224;
    *(_DWORD *)(pwr_data + 276) = v26;
    mutex_unlock(v28);
LABEL_49:
    v29 = pwr_data;
    if ( *(_DWORD *)(pwr_data + 288) == 3 )
    {
      v30 = *(_QWORD *)(pwr_data + 208);
      *(_DWORD *)(pwr_data + 292) = 131074;
      if ( !v30 )
      {
        printk(&unk_1231E, "send_signal_to_subsystem");
        if ( v3 == 3 )
          goto LABEL_53;
        goto LABEL_65;
      }
      queue_work_on(32, *(_QWORD *)(v29 + 296), v29 + 320);
    }
    if ( v3 == 3 )
    {
LABEL_53:
      v31 = pwr_data;
      if ( v4 == 4 )
      {
        v32 = *(_QWORD *)(pwr_data + 208);
        *(_DWORD *)(pwr_data + 292) = 262145;
        if ( v32 )
          queue_work_on(32, *(_QWORD *)(v31 + 296), v31 + 320);
        else
          printk(&unk_1231E, "send_signal_to_subsystem");
        mutex_lock(pwr_data + 224);
        v20 = pwr_data;
        *(_DWORD *)(pwr_data + 280) = 2;
        goto LABEL_31;
      }
      mutex_lock(pwr_data + 224);
      v36 = pwr_data + 224;
      *(_DWORD *)(pwr_data + 280) = 0;
      mutex_unlock(v36);
    }
LABEL_65:
    if ( v4 != 5 )
      return (unsigned int)v7;
    goto LABEL_30;
  }
  LODWORD(v7) = ((__int64 (__fastcall *)(_QWORD, _QWORD))power_regulators)(0, 0);
  mutex_lock(pwr_data + 224);
  v12 = pwr_data + 224;
  *(_DWORD *)(pwr_data + 272) = 2;
  mutex_unlock(v12);
  if ( v2 == 5 )
  {
    v13 = 3;
  }
  else
  {
    if ( v2 != 1 )
      goto LABEL_20;
    v13 = 0;
  }
  mutex_lock(pwr_data + 224);
  v15 = pwr_data + 224;
  *(_DWORD *)(pwr_data + 276) = v13;
  mutex_unlock(v15);
LABEL_20:
  v16 = pwr_data;
  if ( *(_DWORD *)(pwr_data + 288) == 1 )
  {
    v17 = *(_QWORD *)(pwr_data + 216);
    *(_DWORD *)(pwr_data + 292) = 2;
    if ( !v17 )
    {
      printk(&unk_1378C, "send_signal_to_subsystem");
      if ( v3 != 2 )
        goto LABEL_29;
      goto LABEL_24;
    }
    queue_work_on(32, *(_QWORD *)(v16 + 296), v16 + 352);
  }
  if ( v3 != 2 )
    goto LABEL_29;
LABEL_24:
  v18 = pwr_data;
  if ( v4 == 5 )
  {
    v19 = *(_QWORD *)(pwr_data + 216);
    *(_DWORD *)(pwr_data + 292) = 262145;
    if ( v19 )
      queue_work_on(32, *(_QWORD *)(v18 + 296), v18 + 352);
    else
      printk(&unk_1378C, "send_signal_to_subsystem");
    mutex_lock(pwr_data + 224);
    v20 = pwr_data;
    *(_DWORD *)(pwr_data + 280) = 3;
    goto LABEL_31;
  }
  mutex_lock(pwr_data + 224);
  v21 = pwr_data + 224;
  *(_DWORD *)(pwr_data + 280) = 0;
  mutex_unlock(v21);
LABEL_29:
  if ( v4 == 4 )
  {
LABEL_30:
    mutex_lock(pwr_data + 224);
    v20 = pwr_data;
    *(_DWORD *)(pwr_data + 284) = 1;
LABEL_31:
    mutex_unlock(v20 + 224);
  }
  return (unsigned int)v7;
}
