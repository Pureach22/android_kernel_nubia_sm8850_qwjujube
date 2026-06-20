__int64 __fastcall rmnet_shs_get_core_prio_flow(char a1)
{
  __int64 result; // x0
  int v3; // w9
  char v4; // w10
  _BOOL4 v6; // w12
  _BOOL4 v8; // w13
  _BOOL4 v10; // w13
  _BOOL4 v12; // w13
  _BOOL4 v14; // w13
  _BOOL4 v16; // w12

  if ( (a1 & 1) != 0 )
  {
    if ( (__int64 *)rmnet_shs_cpu_node_tbl[0] == rmnet_shs_cpu_node_tbl )
      return 0;
    result = 0;
    v3 = cpu_num_flows;
    v4 = a1;
    if ( (a1 & 2) == 0 )
    {
LABEL_3:
      if ( (v4 & 4) == 0 )
        goto LABEL_4;
      goto LABEL_25;
    }
  }
  else
  {
    result = 0xFFFFFFFFLL;
    v3 = -1;
    v4 = a1;
    if ( (a1 & 2) == 0 )
      goto LABEL_3;
  }
  if ( (__int64 *)qword_194D0 == &qword_194D0 )
    return 1;
  v6 = v3 == -1 || dword_195EC <= v3;
  if ( v6 )
    result = 1;
  else
    result = (unsigned int)result;
  if ( v6 )
    v3 = dword_195EC;
  if ( (v4 & 4) == 0 )
  {
LABEL_4:
    if ( (v4 & 8) == 0 )
      goto LABEL_5;
    goto LABEL_38;
  }
LABEL_25:
  if ( (__int64 *)qword_194F8 == &qword_194F8 )
    return 2;
  v8 = v3 == -1 || dword_195F0 <= v3;
  if ( v8 )
    result = 2;
  else
    result = (unsigned int)result;
  if ( v8 )
    v3 = dword_195F0;
  if ( (v4 & 8) == 0 )
  {
LABEL_5:
    if ( (v4 & 0x10) == 0 )
      goto LABEL_6;
    goto LABEL_51;
  }
LABEL_38:
  if ( (__int64 *)qword_19520 == &qword_19520 )
    return 3;
  v10 = v3 == -1 || dword_195F4 <= v3;
  if ( v10 )
    result = 3;
  else
    result = (unsigned int)result;
  if ( v10 )
    v3 = dword_195F4;
  if ( (v4 & 0x10) == 0 )
  {
LABEL_6:
    if ( (v4 & 0x20) == 0 )
      goto LABEL_7;
    goto LABEL_64;
  }
LABEL_51:
  if ( (__int64 *)qword_19548 == &qword_19548 )
    return 4;
  v12 = v3 == -1 || dword_195F8 <= v3;
  if ( v12 )
    result = 4;
  else
    result = (unsigned int)result;
  if ( v12 )
    v3 = dword_195F8;
  if ( (v4 & 0x20) == 0 )
  {
LABEL_7:
    if ( (v4 & 0x40) == 0 )
      goto LABEL_8;
    goto LABEL_77;
  }
LABEL_64:
  if ( (__int64 *)qword_19570 == &qword_19570 )
    return 5;
  v14 = v3 == -1 || dword_195FC <= v3;
  if ( v14 )
    result = 5;
  else
    result = (unsigned int)result;
  if ( v14 )
    v3 = dword_195FC;
  if ( (v4 & 0x40) == 0 )
  {
LABEL_8:
    if ( (a1 & 0x80) == 0 )
      return result;
    goto LABEL_90;
  }
LABEL_77:
  if ( (__int64 *)qword_19598 == &qword_19598 )
    return 6;
  v16 = v3 == -1 || dword_19600 <= v3;
  if ( v16 )
    result = 6;
  else
    result = (unsigned int)result;
  if ( v16 )
    v3 = dword_19600;
  if ( a1 < 0 )
  {
LABEL_90:
    if ( (__int64 *)qword_195C0 == &qword_195C0 )
    {
      return 7;
    }
    else if ( dword_19604 <= v3 || v3 == -1 )
    {
      return 7;
    }
    else
    {
      return (unsigned int)result;
    }
  }
  return result;
}
