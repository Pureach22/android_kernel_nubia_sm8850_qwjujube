void __fastcall _qcom_alloc_insert_iova(
        __int64 a1,
        unsigned __int64 *a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        unsigned __int64 *a5,
        char a6,
        int *a7)
{
  int v8; // w21
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x26
  unsigned __int64 *v16; // x25
  __int64 v17; // x0
  unsigned __int64 *v18; // x27
  __int64 v19; // x28
  unsigned __int64 *v20; // x9
  unsigned __int64 v21; // x22
  unsigned __int64 v22; // x10
  unsigned __int64 v23; // x11
  unsigned __int64 v24; // x10
  unsigned __int64 v25; // x8
  bool v26; // cc
  bool v27; // cf
  unsigned __int64 **v28; // x10
  unsigned __int64 *v29; // x11
  unsigned __int64 *v30; // x9
  __int64 v31; // x10
  unsigned __int64 v32; // x10
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x10
  unsigned __int64 v35; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x9
  int v39; // w10
  _BOOL4 v40; // w8
  bool v41; // zf
  __int64 v42; // [xsp+0h] [xbp-10h]
  unsigned __int64 *v43; // [xsp+8h] [xbp-8h] BYREF

  if ( (a2[16] & 0x10000) != 0 )
  {
    if ( (a6 & 1) != 0 )
    {
      v13 = 64 - __clz(a3 - 1);
      if ( (unsigned __int8)a2[16] )
      {
        v14 = (unsigned __int8)a2[16] - __clz(__rbit64(a2[4])) + 12;
        if ( v14 < v13 )
          LOBYTE(v13) = v14;
      }
      v15 = -1LL << v13;
    }
    else
    {
      v15 = -1;
    }
    v16 = a2 + 8;
    v42 = raw_spin_lock_irqsave(a2);
    v17 = rb_prev(a2 + 8);
    v18 = nullptr;
    if ( v17 )
    {
      v19 = -1;
      v20 = a2 + 8;
      v21 = -1;
      while ( 1 )
      {
        v22 = v20[4];
        v23 = *(_QWORD *)(v17 + 24);
        v16 = (unsigned __int64 *)v17;
        if ( a4 >= v22 )
          a4 = v20[4];
        v24 = v22 + ~v23;
        v25 = (a4 - a3) & v15;
        v26 = a4 >= a3 && v25 > v23;
        v27 = !v26 || v24 >= v21;
        if ( !v27 )
        {
          v21 = v24;
          v19 = (a4 - a3) & v15;
          v18 = v20;
          if ( v24 == a3 )
            break;
        }
        v17 = rb_prev(v17);
        v20 = v16;
        if ( !v17 )
          goto LABEL_36;
      }
      if ( v25 != -1 )
      {
LABEL_23:
        v43 = v20;
        a5[3] = a3 + v25 - 1;
        a5[4] = v25;
        if ( v20 )
          v28 = &v43;
        else
          v28 = (unsigned __int64 **)(a2 + 1);
        v29 = *v28;
        if ( *v28 )
        {
          do
          {
            while ( 1 )
            {
              v32 = v29[4];
              v30 = v29;
              if ( v25 >= v32 )
                break;
              v31 = 2;
              v29 = (unsigned __int64 *)v29[2];
              if ( !v29 )
                goto LABEL_33;
            }
            if ( v25 <= v32 )
            {
              __break(0x800u);
              goto LABEL_53;
            }
            v31 = 1;
            v29 = (unsigned __int64 *)v29[1];
          }
          while ( v29 );
LABEL_33:
          v28 = (unsigned __int64 **)&v30[v31];
        }
        else
        {
          v30 = nullptr;
        }
        *a5 = (unsigned __int64)v30;
        a5[1] = 0;
        a5[2] = 0;
        *v28 = a5;
        rb_insert_color(a5);
LABEL_53:
        v8 = 0;
        goto LABEL_54;
      }
    }
    else
    {
      v21 = -1;
      v19 = -1;
LABEL_36:
      v33 = v16[4];
      v34 = a2[5];
      if ( a4 >= v33 )
        v35 = v16[4];
      else
        v35 = a4;
      v36 = v33 - v34;
      v27 = v35 >= a3;
      v37 = (v35 - a3) & v15;
      v39 = v27 && v37 >= v34;
      v40 = v36 < v21;
      v41 = (v39 & v40) == 0;
      if ( (v39 & v40) != 0 )
        v25 = v37;
      else
        v25 = v19;
      if ( v41 )
        v20 = v18;
      else
        v20 = v16;
      if ( v25 != -1 )
        goto LABEL_23;
    }
    v8 = -12;
LABEL_54:
    raw_spin_unlock_irqrestore(a2, v42);
    goto LABEL_55;
  }
  v8 = -22;
LABEL_55:
  *a7 = v8;
}
