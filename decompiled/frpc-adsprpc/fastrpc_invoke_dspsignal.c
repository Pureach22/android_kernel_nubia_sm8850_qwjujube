__int64 __fastcall fastrpc_invoke_dspsignal(__int64 a1, int *a2)
{
  __int64 result; // x0
  int v4; // w8
  unsigned __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 v8; // x0
  int v9; // w8
  unsigned __int64 v10; // x20
  __int64 v11; // x1
  __int64 v12; // x21
  __int64 v13; // x0
  _DWORD *v14; // x26
  __int64 v15; // x27
  _DWORD *v16; // x21
  unsigned __int64 v17; // x20
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x20
  __int64 v21; // x0
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  result = 0;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  if ( *a2 <= 2 )
  {
    if ( v4 == 1 )
    {
      v20 = (unsigned int)a2[1];
      v21 = *(_QWORD *)(a1 + 128);
      if ( (unsigned int)v20 < 0x400 )
      {
        v22[0] = v20 | ((unsigned __int64)*(unsigned int *)(a1 + 244) << 32);
        result = fastrpc_transport_send(v21, v22, 8);
        goto LABEL_34;
      }
      dev_err(*(_QWORD *)(v21 + 168), "Sending bad signal %u for PID %u", v20, *(_DWORD *)(a1 + 240));
      goto LABEL_33;
    }
    if ( v4 == 2 )
      result = fastrpc_dspsignal_wait(a1, (__int64)a2);
  }
  else
  {
    switch ( v4 )
    {
      case 3:
        v10 = (unsigned int)a2[1];
        if ( (unsigned int)v10 <= 0x3FF )
        {
          mutex_lock(a1 + 376);
          v11 = raw_spin_lock_irqsave(a1 + 324);
          v12 = *(_QWORD *)(a1 + 504 + 8 * (v10 >> 8));
          if ( !v12 )
          {
            raw_spin_unlock_irqrestore(a1 + 324, v11);
            v13 = _kmalloc_large_noprof(10240, 3520);
            v12 = v13;
            if ( !v13 )
            {
              dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "Unable to allocate signal group\n");
              mutex_unlock(a1 + 376);
              result = 4294967284LL;
              break;
            }
            v14 = (_DWORD *)(v13 + 32);
            v15 = 256;
            do
            {
              *(v14 - 8) = 0;
              _init_swait_queue_head(v14 - 6, "&x->wait", &init_completion___key);
              --v15;
              *v14 = 0;
              v14 += 10;
            }
            while ( v15 );
            v11 = raw_spin_lock_irqsave(a1 + 324);
            *(_QWORD *)(a1 + 504 + 8 * (v10 >> 8)) = v12;
          }
          v16 = (_DWORD *)(v12 + 40LL * (unsigned __int8)v10);
          if ( v16[8] )
          {
            raw_spin_unlock_irqrestore(a1 + 324, v11);
            mutex_unlock(a1 + 376);
            dev_err(
              *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
              "Attempting to create signal %u already in use (state %u)\n",
              v10,
              v16[8]);
            result = 4294967280LL;
            break;
          }
          *v16 = 0;
          v16[8] = 1;
          raw_spin_unlock_irqrestore(a1 + 324, v11);
          mutex_unlock(a1 + 376);
          goto LABEL_29;
        }
        goto LABEL_33;
      case 4:
        v17 = (unsigned int)a2[1];
        if ( (unsigned int)v17 <= 0x3FF )
        {
          v6 = raw_spin_lock_irqsave(a1 + 324);
          v18 = *(_QWORD *)(a1 + ((v17 >> 5) & 0x7FFFFF8) + 504);
          if ( v18 )
          {
            v19 = v18 + 40LL * (unsigned __int8)v17;
            if ( v19 )
            {
              if ( *(_DWORD *)(v19 + 32) )
              {
                *(_DWORD *)(v19 + 32) = 0;
                goto LABEL_27;
              }
            }
          }
          raw_spin_unlock_irqrestore(a1 + 324, v6);
          dev_err(
            *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
            "Attempting to destroy unused signal %u\n",
            (unsigned int)v17);
LABEL_37:
          result = 4294967294LL;
          break;
        }
LABEL_33:
        result = 4294967274LL;
        break;
      case 5:
        v5 = (unsigned int)a2[1];
        if ( (unsigned int)v5 <= 0x3FF )
        {
          v6 = raw_spin_lock_irqsave(a1 + 324);
          v7 = *(_QWORD *)(a1 + ((v5 >> 5) & 0x7FFFFF8) + 504);
          if ( v7 )
          {
            v8 = v7 + 40LL * (unsigned __int8)v5;
            if ( v8 )
            {
              v9 = *(_DWORD *)(v8 + 32);
              if ( v9 == 3 )
              {
LABEL_28:
                raw_spin_unlock_irqrestore(a1 + 324, v6);
LABEL_29:
                result = 0;
                break;
              }
              if ( v9 )
              {
                *(_DWORD *)(v8 + 32) = 3;
LABEL_27:
                complete_all();
                goto LABEL_28;
              }
            }
          }
          raw_spin_unlock_irqrestore(a1 + 324, v6);
          dev_err(
            *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
            "Attempting to cancel unused signal %u\n",
            (unsigned int)v5);
          goto LABEL_37;
        }
        goto LABEL_33;
    }
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
