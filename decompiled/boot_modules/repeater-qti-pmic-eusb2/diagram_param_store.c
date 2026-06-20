__int64 __fastcall diagram_param_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v6; // x0
  char *v8; // x20
  int v9; // w0
  int v10; // w21

  v4 = *(_QWORD *)(a1 + 152);
  if ( v4 )
  {
    v6 = kstrndup(a3, a4, 3264);
    if ( !v6 )
      return -12;
    v8 = (char *)v6;
    if ( *(_BYTE *)(v6 + a4 - 1) == 10 )
      *(_BYTE *)(v6 + a4 - 1) = 0;
    mutex_lock(v4 + 32);
    if ( !strcmp(v8, "default") )
    {
      dev_info(*(_QWORD *)(v4 + 16), "apply oem default diagram parameters\n");
      *(_BYTE *)(v4 + 80) = 1;
    }
    else
    {
      if ( *(_BYTE *)(v4 + 80) == 1 )
        *(_BYTE *)(v4 + 80) = 0;
      dev_info(*(_QWORD *)(v4 + 16), "save user input parameters: %s\n", v8);
      v9 = user_input_param_save(v4, v8);
      if ( v9 < 1 )
      {
        v10 = v9;
        goto LABEL_15;
      }
      user_input_param_override((int *)v4);
    }
    v10 = a4;
LABEL_15:
    mutex_unlock(v4 + 32);
    kfree(v8);
    return v10;
  }
  return -22;
}
