import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { BindeoComponent } from './bindeo.component';

describe('BindeoComponent', () => {
  let component: BindeoComponent;
  let fixture: ComponentFixture<BindeoComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ BindeoComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(BindeoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
