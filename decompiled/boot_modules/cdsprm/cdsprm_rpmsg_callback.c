__int64 __fastcall cdsprm_rpmsg_callback(__int64 a1, __int64 *a2, unsigned int a3)
{
  int v4; // w2
  size_t v6; // x2
  int *v7; // x0
  __int64 v9; // x0
  _UNKNOWN **v10; // x0
  int *v11; // x8
  _UNKNOWN **v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  _QWORD *v15; // x1
  int v16; // w11

  if ( !a2 || a3 <= 0x13 )
  {
    dev_err(a1, "Invalid message in rpmsg callback, length: %d, expected: >= %lu\n", a3, 20);
    return 4294967274LL;
  }
  v4 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 >= 0x15u )
  {
    if ( *((_DWORD *)a2 + 1) == a3 )
    {
      if ( v4 == 21 )
      {
        memset(&byte_A508, 0, 0xE08u);
        if ( (unsigned __int64)*((unsigned int *)a2 + 1) - 24 >= 0xE08 )
          v6 = 3592;
        else
          v6 = *((unsigned int *)a2 + 1) - 24LL;
        memcpy(&byte_A508, a2 + 3, v6);
        v7 = &dword_B310;
        goto LABEL_10;
      }
      goto LABEL_50;
    }
    dev_err(a1, "Invalid message in rpmsg callback, length: %d, expected: >= %lu\n", a3, 3616);
    return 4294967274LL;
  }
  if ( v4 <= 8 )
  {
    if ( v4 > 4 )
    {
      if ( v4 != 5 )
      {
        if ( v4 == 7 && byte_A3D8 == 1 )
        {
          if ( !dword_A3E4 )
            return 0;
          v7 = &dword_A3F0;
LABEL_10:
          complete(v7);
          return 0;
        }
LABEL_50:
        dev_err(a1, "Received incorrect msg feature %d\n", v4);
        return 0;
      }
      if ( (byte_A3D8 & 1) == 0 )
        goto LABEL_50;
    }
    else if ( v4 == 1 )
    {
      v9 = raw_spin_lock_irqsave(&qword_A318);
      off_A4D8 = (_UNKNOWN *)qword_A4D0;
      raw_spin_unlock_irqrestore(&qword_A318, v9);
      if ( !off_A4D8 )
        return 0;
    }
    else if ( v4 != 2 || (byte_A48A & 1) == 0 )
    {
      goto LABEL_50;
    }
LABEL_38:
    v10 = (_UNKNOWN **)raw_spin_lock_irqsave((char *)&qword_A318 + 4);
    if ( (unsigned int)dword_A2B0 >= 0x32 )
    {
      __break(0x5512u);
    }
    else
    {
      v11 = &gcdsprm[10 * dword_A2B0];
      v12 = v10;
      if ( (v11[25] & 1) != 0 )
      {
        raw_spin_unlock_irqrestore((char *)&qword_A318 + 4, v10);
        return 4294967284LL;
      }
      v10 = (_UNKNOWN **)(v11 + 16);
      *((_BYTE *)v11 + 100) = 1;
      v14 = *a2;
      v13 = a2[1];
      v11[24] = *((_DWORD *)a2 + 4);
      *((_QWORD *)v11 + 10) = v14;
      *((_QWORD *)v11 + 11) = v13;
      v15 = off_E0;
      if ( (unsigned int)dword_A2B0 < 0x31 )
        v16 = dword_A2B0 + 1;
      else
        v16 = 0;
      dword_A2B0 = v16;
      if ( v10 != &cdsprm_list && off_E0 != v10 && *off_E0 == (_UNKNOWN *)&cdsprm_list )
      {
        off_E0 = (_UNKNOWN **)(v11 + 16);
        *v10 = &cdsprm_list;
        *((_QWORD *)v11 + 9) = v15;
        *v15 = v10;
LABEL_48:
        raw_spin_unlock_irqrestore((char *)&qword_A318 + 4, v12);
        _wake_up(&cdsprm_wq, 1, 1, 0);
        return 0;
      }
    }
    _list_add_valid_or_report(v10);
    goto LABEL_48;
  }
  if ( v4 <= 13 )
  {
    if ( v4 == 9 )
    {
      if ( byte_A3D8 == 1 )
      {
        dword_A438 = *((_DWORD *)a2 + 1);
        if ( !dword_A3E8 )
          return 0;
        v7 = &dword_A410;
        goto LABEL_10;
      }
      goto LABEL_50;
    }
    if ( v4 != 12 )
      goto LABEL_50;
    gcdsprm[0] = *((_DWORD *)a2 + 1);
    goto LABEL_38;
  }
  if ( v4 == 14 )
  {
    dword_99A0 = *((_DWORD *)a2 + 1) == 0;
    return 0;
  }
  else
  {
    if ( v4 != 17 )
      goto LABEL_50;
    if ( *((_DWORD *)a2 + 1) )
      return 0;
    dword_99B0 = dword_99AC;
    return 0;
  }
}
