__int64 __fastcall rmnet_ll_switch(__int64 a1, __int64 a2, int a3)
{
  unsigned int v3; // w23
  unsigned int v4; // w19
  unsigned __int64 v6; // x22
  int v7; // w24
  unsigned __int8 *v8; // x20
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 qos_pt; // x0
  __int64 v13; // x21
  __int64 v14; // x26
  unsigned __int8 *v15; // x27
  __int64 v16; // x23
  unsigned __int8 v17; // t1
  __int64 *bearer_map; // x0
  unsigned __int8 v19; // t1
  __int64 *v20; // x0
  int v21; // w9
  __int64 *v22; // x23
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v3 = -22;
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = *(unsigned __int8 *)(a2 + 1);
    if ( (unsigned __int8)(v4 - 2) < 0xFDu )
    {
      v3 = -95;
      goto LABEL_5;
    }
    v6 = *(unsigned __int8 *)(a2 + 2);
    if ( *(_BYTE *)(a2 + 2) )
    {
      if ( (unsigned int)v6 <= 0xF && a3 - 20LL >= v6 )
      {
        v7 = *(_DWORD *)(a2 + 16);
        v8 = (unsigned __int8 *)(a2 + 20);
        if ( *(_BYTE *)(a2 + 2) )
        {
          v9 = 0;
LABEL_12:
          v10 = 0;
          while ( v9 == v10 || v8[v9] != v8[v10] )
          {
            if ( *(unsigned __int8 *)(a2 + 2) == ++v10 )
            {
              if ( ++v9 == *(unsigned __int8 *)(a2 + 2) )
                goto LABEL_17;
              goto LABEL_12;
            }
          }
          goto LABEL_28;
        }
LABEL_17:
        v23 = 0;
        qos_pt = rmnet_get_qos_pt(a1);
        if ( !qos_pt )
        {
LABEL_28:
          v3 = -22;
          goto LABEL_5;
        }
        v13 = qos_pt;
        raw_spin_lock_bh(qos_pt + 332);
        if ( (_DWORD)v6 )
        {
          v14 = (unsigned int)v6;
          v15 = v8;
          v16 = (unsigned int)v6;
          do
          {
            v17 = *v15++;
            bearer_map = qmi_rmnet_get_bearer_map((__int64 *)v13, v17);
            if ( !bearer_map )
            {
              v3 = -14;
              goto LABEL_33;
            }
            if ( *((_DWORD *)bearer_map + 34) )
            {
              v3 = -16;
              goto LABEL_33;
            }
            --v16;
          }
          while ( v16 );
          v3 = ll_qmap_send_switch(*(unsigned __int8 *)(v13 + 16), v4, (unsigned int)v6, v8, &v23);
          if ( !v3 )
          {
            do
            {
              v19 = *v8++;
              v20 = qmi_rmnet_get_bearer_map((__int64 *)v13, v19);
              if ( v20 )
              {
                v21 = v23;
                *((_BYTE *)v20 + 129) = v4;
                *((_BYTE *)v20 + 131) = -1;
                v22 = v20;
                *((_DWORD *)v20 + 34) = 1;
                *((_DWORD *)v20 + 35) = v21;
                *((_BYTE *)v20 + 130) = (v7 << 30 >> 31) & 3;
                *((_DWORD *)v20 + 36) = v7;
                *((_BYTE *)v20 + 148) = 0;
                mod_timer(v20 + 19, jiffies + 1250LL);
                *((_DWORD *)v22 + 48) = *(_DWORD *)(a2 + 8);
                *((_DWORD *)v22 + 49) = *(_DWORD *)(a2 + 12);
              }
              --v14;
            }
            while ( v14 );
            v3 = 0;
          }
        }
        else
        {
          v3 = ll_qmap_send_switch(*(unsigned __int8 *)(v13 + 16), v4, 0, v8, &v23);
        }
LABEL_33:
        raw_spin_unlock_bh(v13 + 332);
      }
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v3;
}
