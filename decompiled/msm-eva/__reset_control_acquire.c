__int64 __fastcall _reset_control_acquire(__int64 a1, char *s2)
{
  __int64 v2; // x8
  _QWORD *v4; // x20
  _QWORD *v5; // x21
  __int64 result; // x0
  int v7; // w0
  int v8; // w0
  int v9; // w0
  int v10; // w0
  int v11; // w0
  int v12; // w0
  int v13; // w0
  int v14; // w0
  int v15; // w0
  int v16; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v18; // x8

  v2 = *(_QWORD *)(a1 + 2208);
  v4 = *(_QWORD **)(v2 + 312);
  v5 = &v4[3 * *(unsigned int *)(v2 + 320)];
  if ( v4 < v5 )
  {
    while ( strcmp((const char *)v4[2], s2) )
    {
      v4 += 3;
      if ( v4 >= v5 )
        goto LABEL_4;
    }
    if ( *((_DWORD *)v4 + 3) == 1 )
      return 0;
    v7 = reset_control_acquire(*v4);
    if ( v7 )
    {
      if ( v7 != -16 )
        goto LABEL_37;
      usleep_range_state(500, 1000, 2);
      v8 = reset_control_acquire(*v4);
      if ( v8 )
      {
        if ( v8 != -16 )
          goto LABEL_37;
        usleep_range_state(500, 1000, 2);
        v9 = reset_control_acquire(*v4);
        if ( v9 )
        {
          if ( v9 != -16 )
            goto LABEL_37;
          usleep_range_state(500, 1000, 2);
          v10 = reset_control_acquire(*v4);
          if ( v10 )
          {
            if ( v10 != -16 )
              goto LABEL_37;
            usleep_range_state(500, 1000, 2);
            v11 = reset_control_acquire(*v4);
            if ( v11 )
            {
              if ( v11 != -16 )
                goto LABEL_37;
              usleep_range_state(500, 1000, 2);
              v12 = reset_control_acquire(*v4);
              if ( v12 )
              {
                if ( v12 != -16 )
                  goto LABEL_37;
                usleep_range_state(500, 1000, 2);
                v13 = reset_control_acquire(*v4);
                if ( v13 )
                {
                  if ( v13 != -16 )
                    goto LABEL_37;
                  usleep_range_state(500, 1000, 2);
                  v14 = reset_control_acquire(*v4);
                  if ( v14 )
                  {
                    if ( v14 != -16 )
                      goto LABEL_37;
                    usleep_range_state(500, 1000, 2);
                    v15 = reset_control_acquire(*v4);
                    if ( v15 )
                    {
                      if ( v15 != -16 )
                        goto LABEL_37;
                      usleep_range_state(500, 1000, 2);
                      v16 = reset_control_acquire(*v4);
                      if ( v16 )
                      {
                        if ( v16 == -16 )
                        {
                          usleep_range_state(500, 1000, 2);
                          result = 4294967274LL;
                          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                          {
                            StatusReg = _ReadStatusReg(SP_EL0);
                            printk(
                              &unk_92028,
                              *(unsigned int *)(StatusReg + 1800),
                              *(unsigned int *)(StatusReg + 1804),
                              &unk_8E7CE);
                            return 4294967274LL;
                          }
                          return result;
                        }
LABEL_37:
                        result = 4294967274LL;
                        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                        {
                          v18 = _ReadStatusReg(SP_EL0);
                          printk(&unk_92DD6, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
                          return 4294967274LL;
                        }
                        return result;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      printk(&unk_93946, &unk_8DA84, "__reset_control_acquire", v4[2]);
    *((_DWORD *)v4 + 3) = 1;
    return 0;
  }
LABEL_4:
  result = 4294967274LL;
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_85EBB, &unk_8DA84, "__reset_control_acquire", s2);
    return 4294967274LL;
  }
  return result;
}
