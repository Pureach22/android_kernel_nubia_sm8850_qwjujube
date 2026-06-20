__int64 __fastcall slim_register_controller(__int64 *a1)
{
  __int64 result; // x0
  int v3; // w8
  __int64 v4; // x20
  __int64 v5; // x21
  const char *property; // x0
  const char *v7; // x27
  int variable_u32_array; // w0
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+8h] [xbp-18h] BYREF
  __int16 v11; // [xsp+Ch] [xbp-14h]
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = ida_alloc_range(&ctrl_ida, 0, 0xFFFFFFFFLL, 3264);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_14;
  v3 = *((_DWORD *)a1 + 11);
  *((_DWORD *)a1 + 2) = result;
  if ( !v3 )
  {
    *((_DWORD *)a1 + 11) = 1;
    if ( *((_DWORD *)a1 + 12) )
      goto LABEL_4;
LABEL_16:
    *((_DWORD *)a1 + 12) = 10;
    goto LABEL_4;
  }
  if ( !*((_DWORD *)a1 + 12) )
    goto LABEL_16;
LABEL_4:
  a1[8] = 0;
  *((_DWORD *)a1 + 14) = 0;
  *((_DWORD *)a1 + 15) = 268435461;
  a1[18] = 0x1000000400000000LL;
  a1[19] = 0;
  a1[20] = 0;
  _mutex_init(a1 + 10, "&ctrl->lock", &slim_register_controller___key);
  _mutex_init(a1 + 27, "&ctrl->sched.m_reconf", &slim_register_controller___key_2);
  *((_DWORD *)a1 + 46) = 0;
  _init_swait_queue_head(a1 + 24, "&x->wait", &init_completion___key);
  v4 = *a1;
  *((_DWORD *)a1 + 42) = 0;
  result = *(_QWORD *)(v4 + 744);
  if ( result )
  {
    result = of_get_next_child(result, 0);
    if ( result )
    {
      v5 = result;
      do
      {
        v11 = 0;
        v10 = 0;
        v12[0] = 0;
        v9 = 0;
        property = (const char *)of_get_property(v5, "compatible", 0);
        if ( property )
        {
          v7 = property;
          if ( sscanf(property, "slim%x,%x", (char *)&v9 + 4, &v9) == 2 )
          {
            variable_u32_array = of_property_read_variable_u32_array(v5, "reg", v12, 2, 0);
            if ( variable_u32_array < 0 )
            {
              dev_err(v4, "Device and Instance id not found:%d\n", variable_u32_array);
            }
            else
            {
              BYTE1(v10) = v12[0];
              LOBYTE(v10) = BYTE4(v12[0]);
              v11 = WORD2(v9);
              HIWORD(v10) = v9;
              slim_alloc_device(a1, &v10, v5);
            }
          }
          else
          {
            dev_err(v4, "Manf ID & Product code not found %s\n", v7);
          }
        }
        result = of_get_next_child(*(_QWORD *)(*a1 + 744), v5);
        v5 = result;
      }
      while ( result );
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
