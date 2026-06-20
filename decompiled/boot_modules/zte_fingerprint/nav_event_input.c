__int64 __fastcall nav_event_input(int a1)
{
  unsigned int v1; // w19
  void *v3; // x0

  if ( a1 > 5 )
  {
    if ( a1 <= 7 )
    {
      if ( a1 == 7 )
      {
        v1 = 114;
      }
      else
      {
        printk(&unk_9304);
        v1 = 106;
      }
      goto LABEL_8;
    }
    switch ( a1 )
    {
      case 8:
        printk(&unk_95A0);
        v1 = 216;
        break;
      case 9:
        printk(&unk_97BB);
        v1 = 217;
        break;
      case 10:
        printk(&unk_913D);
        v1 = 115;
        break;
      default:
LABEL_24:
        printk(&unk_8583);
        v1 = 0;
        break;
    }
LABEL_8:
    input_event(qword_83A0, 1, v1, 1);
    input_event(qword_83A0, 0, 0, 0);
    input_event(qword_83A0, 1, v1, 0);
    return input_event(qword_83A0, 0, 0, 0);
  }
  if ( a1 > 2 )
  {
    if ( a1 == 3 )
    {
      v1 = 103;
    }
    else if ( a1 == 4 )
    {
      printk(&unk_8B9C);
      v1 = 108;
    }
    else
    {
      printk(&unk_8E0E);
      v1 = 105;
    }
    goto LABEL_8;
  }
  if ( a1 == 1 )
  {
    v3 = &unk_86D9;
    return printk(v3);
  }
  if ( a1 != 2 )
    goto LABEL_24;
  v3 = &unk_9794;
  return printk(v3);
}
