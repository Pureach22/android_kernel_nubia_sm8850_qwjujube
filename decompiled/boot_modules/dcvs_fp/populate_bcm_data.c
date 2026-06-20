__int64 __fastcall populate_bcm_data(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v6; // x0
  unsigned int string; // w0
  int addr; // w0
  const char *v9; // x2
  unsigned __int64 v10; // x0
  unsigned int v11; // w20
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  const char *v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 744);
  v13 = 0;
  v14[0] = nullptr;
  string = of_property_read_string(v6, a3, v14);
  if ( (string & 0x80000000) != 0 )
  {
    v11 = string;
    dev_err(a1, "Error reading %s: %d\n", a3, string);
  }
  else
  {
    addr = cmd_db_read_addr(v14[0]);
    v9 = v14[0];
    *a2 = addr;
    if ( addr )
    {
      v10 = cmd_db_read_aux_data(v9, &v13);
      if ( v10 >= 0xFFFFFFFFFFFFF001LL )
      {
        v11 = v10;
        dev_err(a1, "Error reading %s aux data: %d\n", v14[0], (unsigned int)v10);
      }
      else if ( v13 == 8 )
      {
        a2[1] = *(_DWORD *)v10 / 0x3E8u;
        a2[2] = *(unsigned __int16 *)(v10 + 4);
        a2[3] = *(unsigned __int8 *)(v10 + 6);
        v11 = 0;
      }
      else
      {
        dev_err(a1, "Bad data len for %s: %lu\n", v14[0], v13);
        v11 = -22;
      }
    }
    else
    {
      dev_err(a1, "Error getting addr for: %s\n", v9);
      v11 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
