__int64 __fastcall wcd9378_tx_connect_port(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v4; // x0
  __int64 v5; // x9
  unsigned int v6; // w10
  unsigned int v7; // w8
  int v8; // w10
  _DWORD *v9; // x8
  unsigned __int64 v10; // x8
  __int64 v11; // x0
  __int64 result; // x0
  int v13; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v14[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v15[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v16[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v17[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = *(_QWORD *)(v4 + 152);
  if ( *(_DWORD *)(v5 + 468) != (unsigned __int8)a2 )
  {
    if ( *(_DWORD *)(v5 + 488) == (unsigned __int8)a2 )
    {
      v6 = 0;
      v7 = 1;
      goto LABEL_135;
    }
    if ( *(_DWORD *)(v5 + 508) == (unsigned __int8)a2 )
    {
      v6 = 0;
      v7 = 2;
      goto LABEL_135;
    }
    if ( *(_DWORD *)(v5 + 528) == (unsigned __int8)a2 )
    {
      v6 = 0;
      v7 = 3;
      goto LABEL_135;
    }
    if ( *(_DWORD *)(v5 + 548) == (unsigned __int8)a2 )
    {
      v6 = 0;
      v7 = 4;
      goto LABEL_135;
    }
    if ( *(_DWORD *)(v5 + 568) == (unsigned __int8)a2 )
    {
      v6 = 0;
      v7 = 5;
      goto LABEL_135;
    }
    if ( *(_DWORD *)(v5 + 588) == (unsigned __int8)a2 )
    {
      v6 = 0;
      v7 = 6;
      goto LABEL_135;
    }
    if ( *(_DWORD *)(v5 + 608) == (unsigned __int8)a2 )
    {
      v6 = 0;
LABEL_17:
      v7 = 7;
      goto LABEL_135;
    }
    v8 = *(unsigned __int8 *)(v5 + 464);
    if ( *(_BYTE *)(v5 + 464) )
    {
      if ( *(_DWORD *)(v5 + 628) == (unsigned __int8)a2 )
      {
        v7 = 0;
        v6 = 1;
        goto LABEL_135;
      }
      if ( *(_DWORD *)(v5 + 648) == (unsigned __int8)a2 )
      {
        v6 = 1;
        v7 = 1;
        goto LABEL_135;
      }
      if ( *(_DWORD *)(v5 + 668) == (unsigned __int8)a2 )
      {
        v7 = 2;
        v6 = 1;
        goto LABEL_135;
      }
      if ( *(_DWORD *)(v5 + 688) == (unsigned __int8)a2 )
      {
        v7 = 3;
        v6 = 1;
        goto LABEL_135;
      }
      if ( *(_DWORD *)(v5 + 708) == (unsigned __int8)a2 )
      {
        v7 = 4;
        v6 = 1;
        goto LABEL_135;
      }
      if ( *(_DWORD *)(v5 + 728) == (unsigned __int8)a2 )
      {
        v7 = 5;
        v6 = 1;
        goto LABEL_135;
      }
      if ( *(_DWORD *)(v5 + 748) == (unsigned __int8)a2 )
      {
        v7 = 6;
        v6 = 1;
        goto LABEL_135;
      }
      if ( *(_DWORD *)(v5 + 768) == (unsigned __int8)a2 )
      {
        v7 = 7;
        v6 = 1;
        goto LABEL_135;
      }
      if ( v8 != 1 )
      {
        if ( *(_DWORD *)(v5 + 788) == (unsigned __int8)a2 )
        {
          v7 = 0;
          v6 = 2;
          goto LABEL_135;
        }
        if ( *(_DWORD *)(v5 + 808) == (unsigned __int8)a2 )
        {
          v7 = 1;
          v6 = 2;
          goto LABEL_135;
        }
        if ( *(_DWORD *)(v5 + 828) == (unsigned __int8)a2 )
        {
          v6 = 2;
          v7 = 2;
          goto LABEL_135;
        }
        if ( *(_DWORD *)(v5 + 848) == (unsigned __int8)a2 )
        {
          v7 = 3;
          v6 = 2;
          goto LABEL_135;
        }
        if ( *(_DWORD *)(v5 + 868) == (unsigned __int8)a2 )
        {
          v7 = 4;
          v6 = 2;
          goto LABEL_135;
        }
        if ( *(_DWORD *)(v5 + 888) == (unsigned __int8)a2 )
        {
          v7 = 5;
          v6 = 2;
          goto LABEL_135;
        }
        if ( *(_DWORD *)(v5 + 908) == (unsigned __int8)a2 )
        {
          v7 = 6;
          v6 = 2;
          goto LABEL_135;
        }
        if ( *(_DWORD *)(v5 + 928) == (unsigned __int8)a2 )
        {
          v7 = 7;
          v6 = 2;
          goto LABEL_135;
        }
        if ( v8 != 2 )
        {
          if ( *(_DWORD *)(v5 + 948) == (unsigned __int8)a2 )
          {
            v7 = 0;
            v6 = 3;
            goto LABEL_135;
          }
          if ( *(_DWORD *)(v5 + 968) == (unsigned __int8)a2 )
          {
            v7 = 1;
            v6 = 3;
            goto LABEL_135;
          }
          if ( *(_DWORD *)(v5 + 988) == (unsigned __int8)a2 )
          {
            v7 = 2;
            v6 = 3;
            goto LABEL_135;
          }
          if ( *(_DWORD *)(v5 + 1008) == (unsigned __int8)a2 )
          {
            v6 = 3;
            v7 = 3;
            goto LABEL_135;
          }
          if ( *(_DWORD *)(v5 + 1028) == (unsigned __int8)a2 )
          {
            v7 = 4;
            v6 = 3;
            goto LABEL_135;
          }
          if ( *(_DWORD *)(v5 + 1048) == (unsigned __int8)a2 )
          {
            v7 = 5;
            v6 = 3;
            goto LABEL_135;
          }
          if ( *(_DWORD *)(v5 + 1068) == (unsigned __int8)a2 )
          {
            v7 = 6;
            v6 = 3;
            goto LABEL_135;
          }
          if ( *(_DWORD *)(v5 + 1088) == (unsigned __int8)a2 )
          {
            v7 = 7;
            v6 = 3;
            goto LABEL_135;
          }
          if ( v8 != 3 )
          {
            if ( *(_DWORD *)(v5 + 1108) == (unsigned __int8)a2 )
            {
              v7 = 0;
              v6 = 4;
              goto LABEL_135;
            }
            if ( *(_DWORD *)(v5 + 1128) == (unsigned __int8)a2 )
            {
              v7 = 1;
              v6 = 4;
              goto LABEL_135;
            }
            if ( *(_DWORD *)(v5 + 1148) == (unsigned __int8)a2 )
            {
              v7 = 2;
              v6 = 4;
              goto LABEL_135;
            }
            if ( *(_DWORD *)(v5 + 1168) == (unsigned __int8)a2 )
            {
              v7 = 3;
              v6 = 4;
              goto LABEL_135;
            }
            if ( *(_DWORD *)(v5 + 1188) == (unsigned __int8)a2 )
            {
              v6 = 4;
              v7 = 4;
              goto LABEL_135;
            }
            if ( *(_DWORD *)(v5 + 1208) == (unsigned __int8)a2 )
            {
              v7 = 5;
              v6 = 4;
              goto LABEL_135;
            }
            if ( *(_DWORD *)(v5 + 1228) == (unsigned __int8)a2 )
            {
              v7 = 6;
              v6 = 4;
              goto LABEL_135;
            }
            if ( *(_DWORD *)(v5 + 1248) == (unsigned __int8)a2 )
            {
              v7 = 7;
              v6 = 4;
              goto LABEL_135;
            }
            if ( v8 != 4 )
            {
              if ( *(_DWORD *)(v5 + 1268) == (unsigned __int8)a2 )
              {
                v7 = 0;
                v6 = 5;
                goto LABEL_135;
              }
              if ( *(_DWORD *)(v5 + 1288) == (unsigned __int8)a2 )
              {
                v7 = 1;
                v6 = 5;
                goto LABEL_135;
              }
              if ( *(_DWORD *)(v5 + 1308) == (unsigned __int8)a2 )
              {
                v7 = 2;
                v6 = 5;
                goto LABEL_135;
              }
              if ( *(_DWORD *)(v5 + 1328) == (unsigned __int8)a2 )
              {
                v7 = 3;
                v6 = 5;
                goto LABEL_135;
              }
              if ( *(_DWORD *)(v5 + 1348) == (unsigned __int8)a2 )
              {
                v7 = 4;
                v6 = 5;
                goto LABEL_135;
              }
              if ( *(_DWORD *)(v5 + 1368) == (unsigned __int8)a2 )
              {
                v6 = 5;
                v7 = 5;
                goto LABEL_135;
              }
              if ( *(_DWORD *)(v5 + 1388) == (unsigned __int8)a2 )
              {
                v7 = 6;
                v6 = 5;
                goto LABEL_135;
              }
              if ( *(_DWORD *)(v5 + 1408) == (unsigned __int8)a2 )
              {
                v7 = 7;
                v6 = 5;
                goto LABEL_135;
              }
              if ( v8 != 5 )
              {
                if ( *(_DWORD *)(v5 + 1428) == (unsigned __int8)a2 )
                {
                  v7 = 0;
                  v6 = 6;
                  goto LABEL_135;
                }
                if ( *(_DWORD *)(v5 + 1448) == (unsigned __int8)a2 )
                {
                  v7 = 1;
                  v6 = 6;
                  goto LABEL_135;
                }
                if ( *(_DWORD *)(v5 + 1468) == (unsigned __int8)a2 )
                {
                  v7 = 2;
                  v6 = 6;
                  goto LABEL_135;
                }
                if ( *(_DWORD *)(v5 + 1488) == (unsigned __int8)a2 )
                {
                  v7 = 3;
                  v6 = 6;
                  goto LABEL_135;
                }
                if ( *(_DWORD *)(v5 + 1508) == (unsigned __int8)a2 )
                {
                  v7 = 4;
                  v6 = 6;
                  goto LABEL_135;
                }
                if ( *(_DWORD *)(v5 + 1528) == (unsigned __int8)a2 )
                {
                  v7 = 5;
                  v6 = 6;
                  goto LABEL_135;
                }
                if ( *(_DWORD *)(v5 + 1548) == (unsigned __int8)a2 )
                {
                  v6 = 6;
                  v7 = 6;
                  goto LABEL_135;
                }
                if ( *(_DWORD *)(v5 + 1568) == (unsigned __int8)a2 )
                {
                  v7 = 7;
                  v6 = 6;
                  goto LABEL_135;
                }
                if ( v8 != 6 )
                {
                  if ( *(_DWORD *)(v5 + 1588) == (unsigned __int8)a2 )
                  {
                    v7 = 0;
                    v6 = 7;
                    goto LABEL_135;
                  }
                  if ( *(_DWORD *)(v5 + 1608) == (unsigned __int8)a2 )
                  {
                    v7 = 1;
                    v6 = 7;
                    goto LABEL_135;
                  }
                  if ( *(_DWORD *)(v5 + 1628) == (unsigned __int8)a2 )
                  {
                    v7 = 2;
                    v6 = 7;
                    goto LABEL_135;
                  }
                  if ( *(_DWORD *)(v5 + 1648) == (unsigned __int8)a2 )
                  {
                    v7 = 3;
                    v6 = 7;
                    goto LABEL_135;
                  }
                  if ( *(_DWORD *)(v5 + 1668) == (unsigned __int8)a2 )
                  {
                    v7 = 4;
                    v6 = 7;
                    goto LABEL_135;
                  }
                  if ( *(_DWORD *)(v5 + 1688) == (unsigned __int8)a2 )
                  {
                    v7 = 5;
                    v6 = 7;
                    goto LABEL_135;
                  }
                  if ( *(_DWORD *)(v5 + 1708) == (unsigned __int8)a2 )
                  {
                    v7 = 6;
                    v6 = 7;
                    goto LABEL_135;
                  }
                  if ( *(_DWORD *)(v5 + 1728) == (unsigned __int8)a2 )
                  {
                    v6 = 7;
                    goto LABEL_17;
                  }
                  if ( v8 != 7 )
                    goto LABEL_148;
                }
              }
            }
          }
        }
      }
    }
    result = dev_err(v4, "%s Failed to find slave port for type %u\n", "wcd9378_set_port_params", (unsigned __int8)a2);
LABEL_143:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = 0;
  v7 = 0;
LABEL_135:
  v17[0] = v6;
  v9 = (_DWORD *)(v5 + 468 + 160LL * v6 + 20LL * v7);
  v16[0] = v9[3];
  v15[0] = v9[2];
  v13 = v9[4];
  v14[0] = v9[1];
  if ( (_DWORD)a3 )
    v13 = a3;
  if ( (unsigned __int8)(a2 - 29) > 0xCu )
    goto LABEL_140;
  v10 = *((unsigned __int8 *)*(&off_1E6F8 + (unsigned __int8)(a2 - 29)) + 1);
  if ( v10 < 0xD )
  {
    v14[0] = *(_BYTE *)(v5 + v10 + 3292);
LABEL_140:
    v11 = *(_QWORD *)(v5 + 64);
    if ( a4 )
      result = swr_connect_port(v11, v17, 1, v15, &v13, v16, v14);
    else
      result = swr_disconnect_port(v11, v17, 1, v15, v14);
    goto LABEL_143;
  }
LABEL_148:
  __break(0x5512u);
  return wcd9378_pde_act_ps_check(v4, a2, a3);
}
